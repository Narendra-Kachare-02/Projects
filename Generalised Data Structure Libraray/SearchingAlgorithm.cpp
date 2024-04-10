/////////////////////////////////////////////////
// Header
/////////////////////////////////////////////////
#include <iostream>
using namespace std;

/////////////////////////////////////////////////
// Helper function
/////////////////////////////////////////////////

template <class T>
class ArrayX
{
    // characteristics
    public : 
        T *Arr;
        int iSize;

    // constructor & destructor
    ArrayX(int);
    ~ArrayX();

    // methods
    void Accept();
    void Display();
    bool LinearSearch(T);
    bool BiDirectionalSearch(T);
    bool QuadDirectionalSearch(T);
    bool BinarySearch(T);
    bool CheckSorted();

};

template <class T>
ArrayX<T> :: ArrayX(int i)
{
    this->iSize = i;
    this->Arr = new T[iSize];
}

template <class T>
ArrayX<T> :: ~ArrayX()
{
    delete []Arr;
}

template <class T>
void ArrayX<T> :: Accept()
{

    cout<<"Enter the elements : \n";
    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];
    }
    cout<<"\n";
}

template <class T>
void ArrayX<T> :: Display()
{

    cout<<"Elements of the Array will be : \n";
    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<"|"<<Arr[iCnt]<<"|->";
    }
    cout<<"\n";
}

template <class T>
bool ArrayX<T> :: LinearSearch(T iNo)
{
    bool flag = false;
    int iCnt = 0;
    for(iCnt = 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] == iNo)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <class T>
bool ArrayX<T> :: BiDirectionalSearch(T iNo)
{
    bool flag = false;
    int iStart = 0, iEnd = (iSize-1); 
    while(iStart <= iEnd)
    {
        if((Arr[iStart] == iNo) || (Arr[iEnd] == iNo))
        {

            flag = true;
            break;
        }
        iStart++;
        iEnd--;
    }
    return flag;
}

template <class T>
bool ArrayX<T> :: QuadDirectionalSearch(T iNo)
{
    bool flag = false;
    int iStart = 0, iEnd = (iSize-1); 
    int iMidL = (iSize/2);
    int iMidR = iMidL+1;
    while(iStart <= iEnd)
    {
        if((Arr[iStart] == iNo) || (Arr[iEnd] == iNo) || (Arr[iMidL] == iNo) || (Arr[iMidR] == iNo) )
        { 
            flag = true;
            break;
        }
        iStart++;
        iMidL--;
        iMidR++;
        iEnd--;
    }
    return flag;
}

template <class T>
bool ArrayX<T> :: BinarySearch(T iNo)
{
    bool flag = false;
    int iStart = 0; 
    int iEnd = 0;
    int iMid = 0;

    iEnd = iSize-1;

    while(iStart <= iEnd)
    {

        iMid = iStart + (iEnd - iStart) / 2;
        if((Arr[iMid] == iNo) || (Arr[iStart] == iNo) || (Arr[iEnd] == iNo))
        {
            flag = true;
            break;
        }
        else if(Arr[iMid] < iNo)
        {
            iStart = iMid + 1;
        }
        else if(Arr[iMid] > iNo)
        {
            iEnd = iMid - 1;
        }
    }
    return flag;
}

template <class T>
bool ArrayX<T> :: CheckSorted()
{
    bool flag = false;
    for(int iCnt = 0; iCnt < iSize-1; iCnt++)
    {
        if(Arr[iCnt] <= Arr[iCnt+1])
        {
            flag = true;
            continue;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return flag;
}




/////////////////////////////////////////////////
// Entry point function
/////////////////////////////////////////////////

int main()
{
    int iValue = 0;
    bool bRet = false;

    cout<<"Enter the number of elements : \n";
    cin>>iValue;

    // static object : ArrayX <int>obj(iValue);

    ArrayX<int> *aobj = new ArrayX<int>( iValue);
    aobj->Accept();
    aobj->Display();
    bRet = aobj->CheckSorted();
    if(bRet == true)
    {
        cout<<"Array is sorted\n";
    }
    else
    {
        cout<<"Array is not sorted\n";
    }

    return 0;
}