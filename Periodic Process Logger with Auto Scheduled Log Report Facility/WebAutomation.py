"""

    Automation script which accept time interval from user and create log file in that Marvellous directory which contains informations of all running processes
    after creating the log file send that log  file through mail.

"""
################################################
# Python import mmodules
################################################
from sys import argv
import os
import psutil
import time
import schedule
from urllib import request, error
from email import encoders 
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.base import MIMEBase
import smtplib

################################################
# Function Name : is_connected
# Description : function create schedule log file list each second
# Input : foldername
# Output : listprocess
# Author : Narendra Mahadev Kachare
# Date : 24/11/2023
################################################
def is_connected():
    try:
        request.urlopen("https://www.youtube.com/",timeout=1)
        return True
    except error.URLError() as aobj:
        return False

################################################
# Function Name : MailSender 
# Description : function create and then send mail according to mail content (To,From,Subject,Body)
# Input : filename,time
# Output : 
# Author : Narendra Mahadev Kachare
# Date : 24/11/2023
################################################
def MailSender(fname,time):
    try:
        fromaddr = "_____@gmail.com"
        
        toaddr = "_______@gmail.com"

        msg = MIMEMultipart()
        msg['From'] = fromaddr

        msg['To'] = toaddr

        body = """
        Hello %s
        Welcome to Marvellous Infosystems.
        Please find attached documnet which contains Log of Running process.
        Log file is created at : %s
        
        This is auto generated mail.
        
        Thanks & Regards,
        Piyush Manohar Khairnar
        Marvellous Infosystem
        """%(toaddr,time)

        Subject = """
        Marvellous Infosystems Process log generated at : %s
        """%(time)

        msg['Subject'] = Subject

        msg.attach(MIMEText(body,'plain'))

        attachement = open(fname,"rb")

        p = MIMEBase('application','octet-stream')

        p.set_payload((attachement).read())

        encoders.encode_base64(p)

        p.add_header('Content-Dispostion',"attachment : fname = %s"%fname)

        msg.attach(p)

        s = smtplib.SMTP('smtp.gmail.com',587)

        s.starttls()

        s.login(fromaddr,"______")   # avboaxahzanvntxg


        text = msg.as_string()

        s.sendmail(fromaddr,toaddr, text)

        s.quit()
    except Exception as E:
        print("Mail unable to send dur to",E)

################################################
# Function Name : ProcessMemoryLogSchedule
# Description : function create log file list having running process at every 1 sec
# Input : foldername
# Output : listprocess
# Author : Narendra Mahadev Kachare
# Date : 24/11/2023
################################################
def ProcessMemoryLogSchedule(foldername = "Marvellous"):
    # Create empty list
    listprocess = []
    separator = "-"*94 + "\n"

    print("Inside Logprocesss")
    for proc in psutil.process_iter():
        pinfo = proc.as_dict(['name','username','pid'])
        pinfo['vms'] = proc.memory_info().vms / 1024*1024
        listprocess.append(pinfo)
    
    # create log file 
    flag = os.path.isdir(foldername)
    if flag == False:
        os.mkdir(foldername)
        print("%s folder successfully created"%foldername)
        
    exist = os.path.isabs(foldername)
    if exist == False:
        foldername = os.path.abspath(foldername)
    
    
    filename = "Marvellous_Log_"+str((time.ctime()).replace(" ","_").replace(":","."))
    fname = os.path.join(foldername,(filename+".log"))

    afile = open(fname,"w")
    afile.write(separator+filename+"\n"+separator)
    afile.write("Total running process will be : %d"%(len(listprocess))+"\n")

    for elements in listprocess:
        afile.write(str(elements)+"\n")
    print("Log file successfully created")

    connection = is_connected()
    if connection == True:
        print("Internet connectivity is ON")
        StartT = time.time()
        MailSender(fname,time.ctime())
        EndT = time.time()

        print("Time required to execute the code will be : %d"%(EndT-StartT))
        
    else:
        print("Internet connectivity is OFF")
        exit()



################################################
# Function Name : main 
# Description : function where execution starts
# Input : 
# Output : 
# Author : Narendra Mahadev Kachare
# Date : 30/11/2023
################################################
def main():
    print("Automation Script")
    print("Web Automation")

    if(argv[1] == "-U" or argv[1] == "-u"):
        print("Usage : NameofScript First_argument Second_argument")
        print("Example : WebAutomation.py Marvellous 3sec")
        exit()
    if(argv[1] == "-h" or argv[1] == "-H"):
        print("These script is used to send process log files through mails")
        exit()
    if(len(argv) != 3):
        print("Invalid number of arguments")
        exit()
    
    try:
        schedule.every().seconds.do(ProcessMemoryLogSchedule)
    except ValueError as vobj:
        print("Error : ",vobj)
    except Exception as E:
        print("Error : ",E)
    
    while True:
        schedule.run_pending()
        time.sleep(1)

################################################
# Starter kit
################################################
if __name__ == "__main__":
    main()