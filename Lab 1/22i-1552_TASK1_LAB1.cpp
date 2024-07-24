#include<iostream>

using namespace std;


template <typename T>

T print(T a[9], T b[13])
{
    cout<<endl;
    cout<<"Array A is as follows ->"<<endl;
    for(int i=0;i<9;i++)
    {
        cout<<a[i]<<" , ";
    }
    cout<<endl;
    cout<<endl;
    cout<<"Array B is as follows ->"<<endl;
    for(int i=0;i<13;i++)
    {
        cout<<b[i]<<" , ";
    }
    cout<<endl;
    cout<<endl;
    return 0;
}

template <typename T>

T intersection(T a[9], T b[13])
{
    
    float in[22] = {0};

    for(int i=0;i<13;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(a[j]==b[i])
            {
                in[j] = a[j];
            }
        }
    }
    //cout<<endl;
    cout<<"The intersection is as follows ->"<<endl;

    for(int i=0;i<9;i++)
    {
        if(in[i]!=0)
            cout<<in[i]<<" , ";
    }

    cout<<endl;
    cout<<endl;

    //cout<<"Here0"<<endl;
    return 0;
}

template <typename T>

T Union(T a[9], T b[13])
{
    cout<<"The Union is as follows ->"<<endl;
    float u[22] = {0};

    for(int i=0;i<13;i++)
    {
        u[i] = b[i];
    }
    for(int i=0;i<22;i++)
    {
        if(a[i]!=b[i])
        {
            u[i+13] = a[i];
        }
    }
    
    for(int i=0;i<22;i++)
    {
        cout<<u[i]<<" , ";
    }
    cout<<endl;
    cout<<endl;
    return 0;
}

template <typename T>

T Disjoint(T a[9], T b[13])
{
    cout<<"The disjoint is as follows (1 for true & 0 for false)->"<<endl;
    for(int i=0;i<13;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(a[j]==b[i])
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}

template <typename T>

T find(T a[9], T b[13])
{
    cout<<"Enter what u want to search .... ";
    T ch;
    cin>>ch;

    for(int i=0;i<13;i++)
    {
        if(b[i]==ch)
        {
            return true;
        }
    }
    for(int i=0;i<9;i++)
    {
        if(a[i]==ch)
        {
            return true;
        }
    }
    return false;
}



int main()
{
    float A[9] = {10.43,4.3,5.61,6.90,11.57,12.11,3.8,2.4,9.5};
    float B[13] = {11.01,12.34,16.5,3.8,8.1,2.4,9.11,12.11,6.75,10.43,20.2,2.1,4.3};

    print<float>(A,B);
    
    intersection<float>(A,B);

    Union<float>(A,B);

    cout<<Disjoint<float>(A,B)<<endl;

    cout<<find<float>(A,B)<<endl;


    return 0;
}