
//////////////////////////////////////////////////////////////////////////////////////////////////
// Header
//////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////

// Singly linear and singly circular structure

//////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
struct NodeS
{
    T Data;
    struct NodeS *next;
};

//////////////////////////////////////////////////////////////////////////////////////////////////

// Doubly linear and Doubly circular structure

//////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
struct NodeD
{
    T Data;
    struct NodeD * next;
    struct NodeD * prev;
};


//////////////////////////////////////////////////////////////////////////////////////////////////

// Class  : Singly linear linked list

//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLL
{
    public:
        int iCount;
        struct NodeS<T> *First;

    SinglyLL();

    void Display();
    int Count();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(int,T);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    
};

//////////////////////////////////////////////////////////////////////////////////////////////////

// Class  : Singly circular linked list 

//////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class SinglyCL
{
    public:
        int iCount;
        struct NodeS<T> *First;
        struct NodeS<T> *Last;

        SinglyCL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(int,T);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

//////////////////////////////////////////////////////////////////////////////////////////////////

// Class Declaration : Doubly Linear linked list

//////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class DoublyLL
{
    public:
        int iCount;
        NodeD<T> * First;

        DoublyLL();

        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(int,T);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

//////////////////////////////////////////////////////////////////////////////////////////////////

// Class Declaration : Doubly circular linked list

//////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class DoublyCL
{
    public :
        NodeD<T>* First;
        NodeD<T>* Last;
        int iCount;

        DoublyCL();

        int Count();
        void Display();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(int,T);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

//////////////////////////////////////////////////////////////////////////////////////////////////

// class Declaration : ArrayX 

//////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////

// Defination : Singly linear functions 

//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyLL<T> :: SinglyLL()
{
    iCount = 0;
    First = NULL;
}

template <class T>
void SinglyLL<T> :: Display()
{
    cout<<"Elements of the nodes are : \n";
    NodeS<T> *Temp = First;
    while(Temp != NULL)
    {
        cout<<"|"<<Temp->Data<<"|->";
        Temp = Temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T> :: Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T> :: InsertFirst(T No)
{
    // create node
    NodeS<T>* newn = new NodeS<T>;
    
    // Initialise the node
    newn->Data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T> :: InsertLast(T No)
{
    // Create Node
    NodeS<T> *newn = NULL;
    NodeS<T> * Temp = First;

    // Allocate memory to node
    newn = new NodeS<T>;

    // Initialise the node
    newn->next = NULL;
    newn->Data = No;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T> :: DeleteFirst()
{
    NodeS<T> *Temp = First;   
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        free(First);
        First = NULL;
    }
    else
    {
        First = First->next;
        free(Temp);
    }
    iCount--;
}

template <class T>
void SinglyLL<T> :: DeleteLast()
{
    NodeS<T> *Temp = First;   
    if(First == NULL)
    {
        return;
    }
    else if(First->next == NULL)
    {
        free(First);
        First = NULL;
    }
    else
    {
        while(Temp->next->next != NULL)        
        {
            Temp = Temp->next;
        }
        free(Temp->next);
        Temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T> :: InsertAtPos(int iPos, T No)
{
    if((iPos < 1 )|| (iPos > (iCount+1)))
    {
        cout<<"Invalid Position\n";
        return;
    }

    int iRet = 0;
    iRet = Count();
    NodeS<T> *Temp = First;

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == (iRet+1))
    {
        InsertLast(No);
    }
    else
    {
        // create node
        NodeS<T> *newn = NULL;
        
        // Allocate Node
        newn = new NodeS<T>;

        // Initialise the node
        newn->Data = No;
        newn->next = NULL;

        for(int iCnt = 0; iCnt < (iPos-2); iCnt++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T> :: DeleteAtPos(int iPos)
{
    if((iPos > iCount) || (iPos < 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    NodeS<T> *Temp1 = First;
    NodeS<T> *Temp2 = NULL;
    int iRet = Count();
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iRet)
    {
        DeleteLast();
    }
    else
    {
        for(int iCnt = 0; iCnt < (iPos-2); iCnt++)
        {
            Temp1 = Temp1->next;
        }
        Temp2 = Temp1->next;
        Temp1->next = Temp1->next->next;
        free(Temp2);
    }
    iCount--;
}



//////////////////////////////////////////////////////////////////////////////////////////////////

// Defination : Singly circular functions 

//////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyCL<T> :: SinglyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCL<T> :: Display()
{
    NodeS<T>* Temp = First;
    cout<<"Elements of the linked list are : \n";
    for(int iCnt = 0; iCnt <= iCount-1; iCnt++)
    {
        cout<<"|"<<Temp->Data<<"|->";
        Temp = Temp->next;
    }
    cout<<"\n";
}

template <class T>
int SinglyCL<T> :: Count()
{
    return iCount;
}


template <class T>
void SinglyCL<T> :: InsertFirst(T No)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->Data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;
    iCount++;
}

template <class T>
void SinglyCL<T> :: InsertLast(T No)
{
    NodeS<T> * newn = new NodeS<T>;

    newn->Data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = Last->next;
        newn->next = First;
    }
    Last->next = First;
    iCount++;
}

template <class T>
void SinglyCL<T> :: InsertAtPos(int iPos, T No)
{
    if((iPos < 1 )|| (iPos > (iCount+1)))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        NodeS<T>* newn = new NodeS<T>;
        NodeS<T>* Temp = First;

        newn->Data = No;
        newn->next = NULL;

        for(int iCnt = 0; iCnt < (iPos-2); iCnt++)
        {
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        Temp->next = newn;

        iCount++;
    }
}

template <class T>
void SinglyCL<T> :: DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete(First);
        First = NULL;
    }
    else
    {
        First = First->next;
        delete(Last->next);
        Last->next = First;
    }

    iCount--;
}

template <class T>
void SinglyCL<T> :: DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        return;
    }
    else if(First == Last)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        NodeS<T>* Temp = First;
        for(int iCnt = 0; iCnt < (iCount-2); iCnt++)
        {
            Temp = Temp->next;
        }
        Last = Temp;
        delete(Temp->next);
        Last->next = First;
    }
    iCount--;
}

template <class T>
void SinglyCL<T> :: DeleteAtPos(int iPos)
{
    if((iPos > iCount) || (iPos < 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {  
        NodeS<T>* Temp1 = First;
        NodeS<T>* Temp2 = NULL;

        for(int iCnt = 0; iCnt < (iPos-2); iCnt++)
        {
            Temp1 = Temp1->next;
        }
        Temp2 = Temp1->next;
        Temp1->next = Temp1->next->next;
        delete(Temp2);
        iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////

// Defination : Doubly Linear linked list

//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyLL<T> :: DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T> :: Display()
{
    NodeD<T>* Temp = First;
    cout<<"Elements of the linked list are : \n";
    for(int iCnt = 0; iCnt < iCount; iCnt++)
    {
        cout<<"|"<<Temp->Data<<"|<->";
        Temp = Temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyLL<T> :: Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T> :: InsertFirst(T No)
{
    NodeD<T>* newn = new NodeD<T>;

    newn->Data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> :: InsertLast(T No)
{
    NodeD<T>* newn = new NodeD<T>;
    NodeD<T>* Temp = First;

    newn->Data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(Temp->next != NULL)
        {
            Temp = Temp->next;
        }
        Temp->next = newn;
        newn->prev = Temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T> :: InsertAtPos(int iPos, T No)
{
    if((iPos < 1 )|| (iPos > (iCount+1)))
    {
        cout<<"Invalid Position\n";
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        NodeD<T>* newn = new NodeD<T>;
        NodeD<T>* Temp = First;

        newn->Data = No;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 0; iCnt < (iPos-2); iCnt++)
        {
            Temp = Temp->next;
        }

        newn->next = Temp->next;
        newn->prev = Temp;
        Temp->next->prev = newn;
        Temp->next = newn;
        iCount++;
    }
}

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    if(First == NULL)
    {
        return;
    }
    else if((First->next == NULL) && (First->prev == NULL))
    {
        delete(First);
        First = NULL;
    }
    else
    {
        First = First->next;
        delete (First->prev);
        First->prev = NULL;
    }

    iCount--;
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    NodeD<T>* Temp = First;
    if(First == NULL)
    {
        return;
    }
    else if((First->next == NULL) && (First->prev == NULL))
    {
        delete(First);
        First = NULL;

    }
    else
    {
        for(int iCnt = 0; iCnt < (iCount-2); iCnt++)
        {
            Temp = Temp->next;
        }
        delete(Temp->next);
        Temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T> :: DeleteAtPos(int iPos)
{
    if((iPos > iCount) || (iPos < 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    NodeD<T>* Temp = First;
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {

        for(int iCnt = 0; iCnt < (iPos-2); iCnt++)
        {
            Temp = Temp->next;
        }
        Temp->next = Temp->next->next;
        delete(Temp->next->prev);
        Temp->next->prev = Temp;
        iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////

// Defination : Doubly circular functions 

//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
DoublyCL<T> :: DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T> :: Display()
{
    NodeD<T>* Temp = First;
    cout<<"Elements of the linked list are : \n";
    for(int iCnt = 0; iCnt < iCount; iCnt++)
    {
        cout<<"|"<<Temp->Data<<"|->";
        Temp = Temp->next;
    }
    cout<<Temp->Data;
    cout<<"\n";

}

template <class T>
int DoublyCL<T> :: Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T> :: InsertFirst(T No)
{
    NodeD<T>* newn = new NodeD<T>;

    newn->Data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    First->prev = Last;
    Last->next = First;
    
    iCount++;

}

template <class T>
void DoublyCL<T> :: InsertLast(T No)
{
    NodeD<T>* newn = new NodeD<T>;

    newn->Data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->prev = Last;
        Last->next = newn;
        Last = Last->next;
    }
    First->prev = Last;
    Last->next = First;

    iCount++;

}

template <class T>
void DoublyCL<T> :: InsertAtPos(int iPos, T No)
{
    if((iPos < 1 )|| (iPos > (iCount+1)))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        NodeD<T>* newn = new NodeD<T>;
        NodeD<T>* Temp = First;

        newn->Data = No;
        newn->next = NULL;
        newn->prev = NULL;

        for(int iCnt = 0; iCnt < (iPos-2); iCnt++)
        {   
            Temp = Temp->next;
        }
        newn->next = Temp->next;
        newn->prev = Temp;
        Temp->next->prev = newn;
        Temp->next = newn;

        iCount++;   
    }
}

template <class T>
void DoublyCL<T> :: DeleteFirst()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete(First->prev);
        First->prev = Last;
        Last->next = First;
    }

    iCount--;
}

template <class T>
void DoublyCL<T> :: DeleteLast()
{
    if(iCount == 0)
    {
        return;
    }
    else if(iCount == 1)
    {
        delete(First);
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last->prev;
        delete(Last->next);
        Last->next = First;
        First->prev = Last;
    }
    iCount--;
}

template <class T>
void DoublyCL<T> :: DeleteAtPos(int iPos)
{
    if((iPos > iCount) || (iPos < 1))
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T>* Temp = First;
        
        for(int iCnt = 0; iCnt < (iPos-2); iCnt++)
        {
            Temp = Temp->next;
        }
        Temp->next = Temp->next->next;
        delete(Temp->next->prev);
        Temp->next->prev = Temp;

        iCount--;
    }
}



//////////////////////////////////////////////////////////////////////////////////////////////////
// Entry point function
//////////////////////////////////////////////////////////////////////////////////////////////////



int main()
{
    SinglyLL<int> obj1;
    obj1.InsertFirst(11);
    obj1.InsertFirst(21);
    obj1.InsertFirst(51);
    obj1.InsertFirst(101);


    // obj1.InsertLast(100);
    // obj1.Display();
    

    return 0;
}

