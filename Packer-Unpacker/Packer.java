import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.JPasswordField;
import java.io.*;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Class of UnPacker Frame
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Unpacker_Frame implements ActionListener
{
    //Declaration of object of Frame class
    public Frame unpackerFrame;

    //Declaration of Text Field
    TextField FileName;

    //Declaration of Buttons
    Button b1Submit;
    Button b2Previous;
    
    //Declaration of Panel
    Panel panel1;
    
    //Declaration of Label
    Label label1;

    public Unpacker_Frame()
    {
        //creates object of Frame class
        unpackerFrame = new Frame("Packer_UnPacker");

        //sets width and height
        unpackerFrame.setSize(800, 400);
        //sets layout of frame
        unpackerFrame.setLayout(new GridBagLayout());
        
        
        unpackerFrame.addWindowListener(new WindowAdapter() 
        {
            public void windowClosing(WindowEvent e)
            {
                System.exit(0);
            }    
        });

        // sets background color
        unpackerFrame.setBackground(Color.gray);

        panel1 = new Panel(new GridBagLayout());
        label1 = new Label("File Name: ");
        FileName = new TextField(30);

        b1Submit = new Button("Submit");
        //adds Action Listener to Submit button
        b1Submit.addActionListener(this);
    
        b2Previous  = new Button("Previous");
        //adds Action Listener to Previous button
        b2Previous.addActionListener(this);

        //creates a GridBagConstraints Layout for lable and Text field
        GridBagConstraints c = new GridBagConstraints();

        c.anchor = GridBagConstraints.LINE_START;
        c.gridx = 0;
        c.gridy = 0;
        panel1.add(label1,c);

        c.anchor = GridBagConstraints.LINE_END;
        c.gridx = 2;
        c.gridy = 0;
        panel1.add(FileName,c);

        //creates a GridBagConstraints Layout for UnPacker Frame 
        GridBagConstraints c1 = new GridBagConstraints();

        c1.gridx = 0;
        c1.gridy = 0;
        c1.gridwidth = 1;
        c1.gridheight = 1;
        c1.weightx = 0.0;
        c1.weighty = 0.0;
        c1.insets = new Insets(5, 5, 5, 5);
        c1.fill = GridBagConstraints.NONE;
        c1.anchor = GridBagConstraints.LINE_START;
        unpackerFrame.add(panel1,c1);

        c1.gridx = 0;
        c1.gridy = 2;
        c1.gridwidth = 1;
        c1.gridheight = 1;
        c1.weightx = 0.0;
        c1.weighty = 0.0;
        c1.insets = new Insets(80, 5, 5, 5);
        c1.fill = GridBagConstraints.NONE;
        c1.anchor = GridBagConstraints.LAST_LINE_START;
        unpackerFrame.add(b1Submit,c1);
        
        c1.gridx = 1;
        c1.gridy = 2;
        c1.gridwidth = 1;
        c1.gridheight = 1;
        c1.weightx = 0.0;
        c1.weighty = 0.0;
        c1.insets = new Insets(80, 5, 5, 5);
        c1.fill = GridBagConstraints.NONE;
        c1.anchor = GridBagConstraints.LAST_LINE_END;
        unpackerFrame.add(b2Previous,c1);

        //Sets visiblity of UnPacker Frame false
        unpackerFrame.setVisible(false);
        
    }

    public void actionPerformed(ActionEvent aobj) 
    {
        try
        {
            if(aobj.getSource() == b1Submit )
            {
                UnPack();
            }
        
            else if(aobj.getSource() == b2Previous)
            {
                Main_Frame mf = new Main_Frame();

                //Sets visiblity of Main Frame false
                mf.mainFrame.setVisible(true);

                //Sets visiblity of UnPacker Frame false
                unpackerFrame.setVisible(false);
            }
        }
        catch(Exception e)
        {

        }
        
    }

    private void UnPack()
    {
        try
        {
        
            // buffer to read 100 bytes of data from the given file 
            byte bHeader[] = new byte[100];
            // String to hold Header
            String HeaderStr;

            String Tokens[];
            //Counter for the number of files unpacked
            int UnpackCount = 0;

            // Variable to hold int return value
            int iRet = 0;

            //Holds File Name
            String FName = FileName.getText();

            //Create object of File class for the given File Name
            File UnPackobj = new File(FName);

            FileInputStream inobj = new FileInputStream(UnPackobj);

            
            /*  Loop runs till end of file
                reads 100 Byte into bHeader on every iteration*/
                
            while((iRet = inobj.read(bHeader,0,100)) > 0)
            {
                //converts byte array bHeader into String
                HeaderStr = new String(bHeader);
                

                /*  Splits the Header into two parts 
                    0.FileName 1.FileSize  */
                Tokens = HeaderStr.split("/");

                // creates object of File class with the name from the Header                    
                File newFileobj = new File(Tokens[0]);
                //creates new file of the name in the Header
                newFileobj.createNewFile();
                
                //System.out.println(newFileobj.getName());

                FileOutputStream outobj = new FileOutputStream(newFileobj);

                //Converts String to Int
                int FileSize = Integer.parseInt(Tokens[1]);

                //Creates the buffer of the FileSize from the Header
                byte Buffer[] = new byte[FileSize];

                //reads the data from the given into Buffer
                inobj.read(Buffer,0,FileSize);
                //writes the data that was read in the Buffer
                outobj.write(Buffer,0,FileSize);

                outobj.close();

                //Increments for every File Unpacked
                UnpackCount++;
            }
            inobj.close();
        }
        catch(Exception e)
        {

        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Class of Packer Frame
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Packer_Frame implements ActionListener
{
    //Declaration of object of Frame class
    public Frame packerFrame;

    //Declaration of Text Fields
    TextField DirName;
    TextField CompFileName;

    //Declaration of Buttons
    Button b1Submit;
    Button b2Previous;

    //Declaration of Panels
    Panel panel1;
    Panel panel2;

    //Declaration of Labels
    Label label1;
    Label label2;

    public Packer_Frame()
    {   
        //creates object of Frame class
        packerFrame = new Frame("Packer_UnPacker");

        //sets width and height
        packerFrame.setSize(800, 400);
        //sets layout of frame
        packerFrame.setLayout(new GridBagLayout());
        
        
        packerFrame.addWindowListener(new WindowAdapter() 
        {
            public void windowClosing(WindowEvent e)
            {
                System.exit(0);
            }    
        });

        // sets background color
        packerFrame.setBackground(Color.gray);

        panel1 = new Panel(new GridBagLayout());
        label1 = new Label("Directory Name: ");
        DirName = new TextField(30);

        panel2 = new Panel(new GridBagLayout());
        label2 = new Label("Final File Name: ");
        CompFileName = new TextField(30);

        b1Submit = new Button("Submit");
        //adds Action Listener to Submit button
        b1Submit.addActionListener(this);

        b2Previous  = new Button("Previous");
        //adds Action Listener to Previous button
        b2Previous.addActionListener(this);

        //creates a GridBagConstraints Layout for lable and Text field
        GridBagConstraints c = new GridBagConstraints();

        c.anchor = GridBagConstraints.LINE_START;
        c.gridx = 0;
        c.gridy = 0;
        panel1.add(label1,c);

        c.anchor = GridBagConstraints.LINE_END;
        c.gridx = 2;
        c.gridy = 0;
        panel1.add(DirName,c);
        
        c.anchor = GridBagConstraints.LINE_START;
        c.gridx = 0;
        c.gridy = 1;
        panel2.add(label2,c);

        c.anchor = GridBagConstraints.LINE_END;
        c.gridx = 2;
        c.gridy = 1;
        panel2.add(CompFileName,c);

        //creates a GridBagConstraints Layout for Packer Frame 
        GridBagConstraints c1 = new GridBagConstraints();

        c1.gridx = 0;
        c1.gridy = 0;
        c1.gridwidth = 1;
        c1.gridheight = 1;
        c1.weightx = 0.0;
        c1.weighty = 0.0;
        c1.insets = new Insets(0, 5, 5, 5);
        c1.fill = GridBagConstraints.NONE;
        c1.anchor = GridBagConstraints.LINE_START;
        packerFrame.add(panel1,c1);

        c1.gridx = 0;
        c1.gridy = 1;
        c1.gridwidth = 1;
        c1.gridheight = 1;
        c1.weightx = 0.0;
        c1.weighty = 0.0;
        c1.insets = new Insets(50, 5, 5, 5);
        c1.fill = GridBagConstraints.NONE;
        c1.anchor = GridBagConstraints.LINE_START;
        packerFrame.add(panel2,c1);

        c1.gridx = 0;
        c1.gridy = 2;
        c1.gridwidth = 1;
        c1.gridheight = 1;
        c1.weightx = 0.0;
        c1.weighty = 0.0;
        c1.insets = new Insets(20, 5, 5, 5);
        c1.fill = GridBagConstraints.NONE;
        c1.anchor = GridBagConstraints.LAST_LINE_START;
        packerFrame.add(b1Submit,c1);
        
        c1.gridx = 1;
        c1.gridy = 2;
        c1.gridwidth = 1;
        c1.gridheight = 1;
        c1.weightx = 0.0;
        c1.weighty = 0.0;
        c1.insets = new Insets(20, 5, 5, 5);
        c1.fill = GridBagConstraints.NONE;
        c1.anchor = GridBagConstraints.LAST_LINE_END;
        packerFrame.add(b2Previous,c1);
        
        //Sets visiblity of Packer Frame false
        packerFrame.setVisible(false);
    }

    // Method to handle the performed actions 
    public void actionPerformed(ActionEvent aobj) 
    {
        try
        {
            if(aobj.getSource() == b1Submit)
            {
                Pack();
            }
            else if(aobj.getSource() == b2Previous)
            {
                Main_Frame mf = new Main_Frame();

                //Sets visiblity of Main Frame true
                mf.mainFrame.setVisible(true);

                //Sets visiblity of Packer Frame false
                packerFrame.setVisible(false);
            }
        }
        catch(Exception e)
        {
            
        }
        
    }

    private void Pack()
    {
        try
        {
            //buffer to store data temperoraly
            byte Buffer[] = new byte[1024];
            // Variable to hold int return value
            int iRet = 0;
            //Counter for the number of files packed
            int PackCount = 0;
            //Variable to hold boolean return value
            boolean bRet = false;
            String Header = null;
            //Holds File name
            String Filename = CompFileName.getText();
            //Holds Directory name
            String FolderName = DirName.getText();
        
            File PackerObj = new File(Filename);
            File FolderObj = new File(FolderName);

            // Create New File 
            bRet = PackerObj.createNewFile();
            

            if(bRet == false)
            {
                // If file creation fails return;
                return;            
            }

            
            FileOutputStream outobj = new FileOutputStream(PackerObj);
            

            // Check if Given Name is a Directory
            bRet = FolderObj.isDirectory();

            //if the Given Name is a Directory
            if(bRet == true)
            {
                // Array containing name of all the files in the Directory
                File list[] = FolderObj.listFiles();

                //Loop iterating for every file in the given Directory
                for( int i = 0; i < list.length ; i++)
                {
                    // checks if the file is a text file or not
                    if((list[i].getName()).endsWith(".txt"))
                    {   
                        //Header : saves file name and size of file
                        Header = list[i].getName()+"/"+list[i].length();

                        //Loop to create 100 Byte Header
                        for(int j = Header.length(); j < 100 ; j++)
                        {
                            Header = Header + "/";
                        }
                        
                        // converts String Header to a byte Array
                        byte bHeader[] = Header.getBytes();

                        //Writes Header into File
                        outobj.write(bHeader,0,bHeader.length); 

                        FileInputStream inobj = new FileInputStream(list[i]);

                        //Loop to write the data
                        while((iRet = inobj.read(Buffer)) != -1)
                        {
                            outobj.write(Buffer,0,iRet);
                        }
                        inobj.close();

                        //Increments for every File packed
                        PackCount++;
                    }
                }
            }

            outobj.close();
        }
        catch(Exception e)
        {

        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Class of Main Frame
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Main_Frame implements ActionListener
{
    //Declaration of object of Frame class
    public Frame mainFrame;

    //Declaration of Buttons
    Button b1Packer;
    Button b2UnPacker;

    public Main_Frame()
    {
        //creates object of Frame class
        mainFrame = new Frame("Packer_UnPacker");

        //sets width and height
        mainFrame.setSize(800, 400);
        //sets layout of frame
        mainFrame.setLayout(new GridBagLayout());
        
        
        mainFrame.addWindowListener(new WindowAdapter() 
        {
            public void windowClosing(WindowEvent e)
            {
                System.exit(0);
            }    
        });

        // sets background color
        mainFrame.setBackground(Color.gray);

        b1Packer = new Button("Pack");
        b1Packer.setPreferredSize(new Dimension(128, 64));
        //adds Action Listener to Submit button
        b1Packer.addActionListener(this);


        b2UnPacker = new Button("Unpack");
        b2UnPacker.setPreferredSize(new Dimension(128, 64));
        //adds Action Listener to Submit button
        b2UnPacker.addActionListener(this);


        //creates a GridBagConstraints Layout for Main Frame
        GridBagConstraints c = new GridBagConstraints();

        c.gridx = 0;
        c.gridy = 0;
        c.gridwidth = 1;
        c.gridheight = 1;
        c.weightx = 0.0;
        c.weighty = 0.0;
        c.insets = new Insets(5, 5, 5, 20);
        c.fill = GridBagConstraints.NONE;
        c.anchor = GridBagConstraints.CENTER;
        mainFrame.add(b1Packer,c);

        c.gridx = 1;
        c.gridy = 0;
        c.gridwidth = 1;
        c.gridheight = 1;
        c.weightx = 0.0;
        c.weighty = 0.0;
        c.insets = new Insets(5, 5, 5, 20);
        c.fill = GridBagConstraints.NONE;
        c.anchor = GridBagConstraints.CENTER;
        mainFrame.add(b2UnPacker,c);

        //Sets visiblity of Main Frame false
        mainFrame.setVisible(false);
    }

    // Method to handle the performed actions 
    public void actionPerformed(ActionEvent aobj) 
    {
        try
        {
            if(aobj.getSource() == b1Packer)
            {
                Packer_Frame pf = new Packer_Frame();
                
                //Sets visiblity of Packer Frame true 
                pf.packerFrame.setVisible(true);
                //Sets visiblity of Main Frame false
                mainFrame.setVisible(false);
            }
            else if(aobj.getSource() == b2UnPacker)
            {
                Unpacker_Frame uf = new Unpacker_Frame(); 

                //Sets visiblity of UnPacker Frame false  
                uf.unpackerFrame.setVisible(true);
                //Sets visiblity of Main Frame false
                mainFrame.setVisible(false);
            }
        }
        catch(Exception e)
        {

        }
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Class of Login Frame
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Login_Frame implements ActionListener
{
    //Declaration of object of Frame class
    Frame loginFrame;

    //Declaration of Text Field
    TextField UserName;

    //Declaration of PasswordField
    JPasswordField PasswordField;

    //Declaration of Button
    Button b1Submit;

    //Declaration of Panels
    Panel panel1;
    Panel panel2;

    //Declaration of Labels
    Label label1;
    Label label2;
    Label label3;

    public Login_Frame()
    {
        //creates object of Frame class
        loginFrame = new Frame("Packer_UnPacker");

        //sets width and height
        loginFrame.setSize(800, 400);
        //sets layout of frame
        loginFrame.setLayout(new GridBagLayout());
        
        
        loginFrame.addWindowListener(new WindowAdapter() 
        {
            public void windowClosing(WindowEvent e)
            {
                System.exit(0);
            }    
        });

        // sets background color
        loginFrame.setBackground(Color.gray);

        label3 = new Label("Invalid Username or Password");

        panel1 = new Panel(new GridBagLayout());
        label1 = new Label("Username: ");
        UserName = new TextField(30);

        panel2 = new Panel(new GridBagLayout());
        label2 = new Label("Password: ");
        PasswordField = new JPasswordField(30);

        b1Submit = new Button("Submit");
        //adds Action Listener to Submit button
        b1Submit.addActionListener(this);

        //creates a GridBagConstraints Layout for lable and Text field
        GridBagConstraints c = new GridBagConstraints();

        c.anchor = GridBagConstraints.CENTER;
        c.gridx = 0;
        c.gridy = 0;
        panel1.add(label1,c);

        c.anchor = GridBagConstraints.CENTER;
        c.gridx = 2;
        c.gridy = 0;
        panel1.add(UserName,c);
        
        c.anchor = GridBagConstraints.CENTER;
        c.gridx = 0;
        c.gridy = 1;
        panel2.add(label2,c);

        c.anchor = GridBagConstraints.CENTER;
        c.gridx = 2;
        c.gridy = 1;
        panel2.add(PasswordField,c);


        //creates a GridBagConstraints Layout for Login Frame 
        GridBagConstraints c1 = new GridBagConstraints();

        c1.gridx = 0;
        c1.gridy = 0;
        c1.gridwidth = 1;
        c1.gridheight = 1;
        c1.weightx = 0.0;
        c1.weighty = 0.0;
        c1.insets = new Insets(5, 5, 5, 5);
        c1.fill = GridBagConstraints.NONE;
        c1.anchor = GridBagConstraints.CENTER;
        loginFrame.add(label3,c1);

        c1.gridx = 0;
        c1.gridy = 1;
        c1.gridwidth = 1;
        c1.gridheight = 1;
        c1.weightx = 0.0;
        c1.weighty = 0.0;
        c1.insets = new Insets(5, 5, 5, 5);
        c1.fill = GridBagConstraints.NONE;
        c1.anchor = GridBagConstraints.CENTER;
        loginFrame.add(panel1,c1);

        c1.gridx = 0;
        c1.gridy = 2;
        c1.gridwidth = 1;
        c1.gridheight = 1;
        c1.weightx = 0.0;
        c1.weighty = 0.0;
        c1.insets = new Insets(5, 5, 5, 5);
        c1.fill = GridBagConstraints.NONE;
        c1.anchor = GridBagConstraints.CENTER;
        loginFrame.add(panel2,c1);

        c1.gridx = 0;
        c1.gridy = 3;
        c1.gridwidth = 1;
        c1.gridheight = 1;
        c1.weightx = 0.0;
        c1.weighty = 0.0;
        c1.insets = new Insets(5, 5, 5, 5);
        c1.fill = GridBagConstraints.NONE;
        c1.anchor = GridBagConstraints.CENTER;
        loginFrame.add(b1Submit,c1);
        
        //Sets visiblity of Login Frame true
        loginFrame.setVisible(true);
        label3.setVisible(false);
    }

    public void actionPerformed(ActionEvent aobj) 
    {
        try
        {
            
            if(aobj.getSource() == b1Submit)
            {
                String User = UserName.getText();
                char Pass[] = PasswordField.getPassword();
        
                String Password = new String(Pass);
                
                //Checks Username and Password
                if((User.equals("Admin")) && (Password.equals("Admin")))
                {
                    Main_Frame mf = new Main_Frame();
        
                    //Sets visiblity of Main Frame true
                    mf.mainFrame.setVisible(true);
        
                    //Sets visiblity of Login Frame false
                    loginFrame.setVisible(false);
                }
                else
                {
                    //displays Incorrect credentilas error
                    label3.setVisible(true);
                }
        
            }
            
        }
        catch(Exception e)
        {

        }
    }

    
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Class of Main Method
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Packer 
{
    public static void main(String args[])
    {
        Login_Frame lf = new Login_Frame();
    }
}


