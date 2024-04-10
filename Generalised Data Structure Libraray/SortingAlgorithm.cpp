/////////////////////////////////////////////////
// Header
/////////////////////////////////////////////////
#include<iostream>
using namespace std;

/////////////////////////////////////////////////
// Helper function
/////////////////////////////////////////////////
template <class T>
class ArrayX
{
    public:
        int iSize;
        T *Arr;
    
    ArrayX(int);
    ~ArrayX();
    void Accept();
    void Display();
    bool CheckSorted();
    void BubbleSortEfficientD();
    void SelectionSort();
    void InsertionSort();
};

template <class T>
ArrayX<T> :: ArrayX(int iNo)
{
    this->iSize = iNo;
    this->Arr = new T[iSize];

}


template <class T>
ArrayX<T> :: ~ArrayX()
{
    delete[] Arr;
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
    int iCnt = 0;
    cout<<"Elements of the array will be : \n";
    for(iCnt = 0; iCnt < iSize-1; iCnt++)
    {
        cout<<"|"<<Arr[iCnt]<<"|->";
    }
    cout<<"|"<<Arr[iCnt]<<"|\n";
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
            continue;;
        }
        else
        {
            flag = false;
            break;
        }
    }
    return flag;
}

template <class T>
void ArrayX<T> :: BubbleSortEfficientD()
{
    int i = 0, j = 0;
    T iSelected;
    bool flag = false;
    for(i = 0; i < iSize-1; i++)
    {
        flag = false;
        for(j = 0; j < iSize-i-1; j++)
        {
            if(Arr[j] < Arr[j+1])
            {
                flag = true;
                iSelected = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = iSelected;
            }
        }
        cout<<j<<"\n";
        if(flag == false)
        {
            break;
        }
        Display();
    }
}


template <class T>
void ArrayX<T> :: SelectionSort()
{
    int i = 0, j = 0;
    T iSelected;
    int iMin_index = 0;
    bool flag = false;


    for(i = 0; i < iSize-1; i++)
    {
        iMin_index = i;
        for(j = i+1; j < iSize; j++)
        {
            if(Arr[iMin_index] > Arr[j])
            {
                iMin_index = j;
            }
            
        }
            iSelected = Arr[i];
            Arr[i] = Arr[iMin_index];
            Arr[iMin_index] = iSelected;
            Display();

    }
    
}

template <class T>
void ArrayX<T> :: InsertionSort()
{
    int i = 0, j = i-1;
    T iSelected;
    bool flag = false;

    for(i = 1; i < iSize; i++)
    {
        j = i-1;
        iSelected = Arr[i];
        flag = false;
        while((iSelected < Arr[j]) && (j >= 0))
        {
            cout<<"HELL\n";
            flag = true;
            Arr[j+1] = Arr[j];
            j--;
        }
        Arr[j+1] = iSelected;
        if(flag == false)
        {
            flag = CheckSorted();
            if(flag == true)
            {
                cout<<"BREAK\n";
                break;
            }   
        }
        Display();
        


    }


}

/////////////////////////////////////////////////
// Entry point function
/////////////////////////////////////////////////

int main()
{
    int iValue = 0;
    cout<<"Enter the size of the array : \n";
    cin>>iValue;

    ArrayX<int> *obj1 = new ArrayX<int>(iValue);

    obj1->Accept();
    obj1->Display();

    obj1->InsertionSort();
    // obj1->SelectionSort();




    delete obj1;

    return 0;
}