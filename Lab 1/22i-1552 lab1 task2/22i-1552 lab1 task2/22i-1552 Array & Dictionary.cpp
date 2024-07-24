/*Syed Arham Ahmed , 22i-1552 , BS-CY-B , practice task 1*/
#include <iostream>
#include <string>
#include <ctime>
#include <random>
#include <cstdlib>
#include <chrono>
#include <algorithm>
using namespace std;

class Customers
{
private:
    long long cnic;
    string name;
    string address;

public:
    Customers()
    {
    }
    Customers(string name, long long cnic, string address)
    {
        this->name = name;
        this->cnic = cnic;
        this->address = address;
    }
    long long get_cnic()
    {
        //cout << "CNIC = " << cnic << endl;
        return cnic;
    }
    string get_name()
    {
        cout << "NAME = " << name << endl;
        return name;
    }
    string get_address()
    {
        cout << "Address = " << address << endl;
        return address;
    }
    void set_cnic(long long id)
    {
        cnic = id;
    }
    void set_address(string addr)
    {
        address = addr;
    }
    void set_name(string n)
    {
        name = n;
    }

    bool search_linear(long long num)
    {
        for (int i = 0; i < 11000; i++)
        {
            if (num == cnic)
            {
                // cout << "Found" << endl;
                return true;
            }
        }
        return false;
    }

    bool search_binary(Customers data[11000], long long cnic)
    {
        
        int counter=0;
        int counter2=0;
        int counter3=0;
        int counter4=0;
        int counter5=0;
        int counter6=0;
        int counter7=0;
        int counter8=0;

        long long *arr;
        long long *arr2;
        long long *arr3;
        long long *arr4;
        long long *arr5;
        long long *arr6;
        long long *arr7;
        long long *arr8;
        //long long *arr9;

        arr = new long long[11000];
        arr2 = new long long[11000];
        arr3 = new long long[11000];
        arr4 = new long long[11000];
        arr5 = new long long[11000];
        arr6 = new long long[11000];
        arr7 = new long long[11000];
        arr8 = new long long[11000];



        // cout<<"Counter == "<<counter<<endl;
        // cout<<"Counter2 == "<<counter2<<endl;

        for(int i=0;i<11000;i++)
        {
            if(data[i].get_cnic()>=1000000000000 && data[i].get_cnic()<2000000000000)
            {
                counter++;
                *(arr+i)=data[i].get_cnic();
            }
            else if(data[i].get_cnic()>=2000000000000 && data[i].get_cnic()<3000000000000)
            {
                counter2++;
                *(arr2+i)=data[i].get_cnic();
            }
            else if(data[i].get_cnic()>=3000000000000 && data[i].get_cnic()<4000000000000)
            {
                counter3++;
                *(arr3+i)=data[i].get_cnic();
            }
            else if(data[i].get_cnic()>=4000000000000 && data[i].get_cnic()<5000000000000)
            {
                counter4++;
                *(arr4+i)=data[i].get_cnic();
            }
            else if(data[i].get_cnic()>=5000000000000 && data[i].get_cnic()<6000000000000)
            {
                counter5++;
                *(arr5+i)=data[i].get_cnic();
            }
            else if(data[i].get_cnic()>=6000000000000 && data[i].get_cnic()<7000000000000)
            {
                counter6++;
                *(arr6+i)=data[i].get_cnic();
            }
            else if(data[i].get_cnic()>=7000000000000 && data[i].get_cnic()<8000000000000)
            {
                counter7++;
                *(arr7+i)=data[i].get_cnic();
            }
            else if(data[i].get_cnic()>=8000000000000 && data[i].get_cnic()<90000000000000)
            {
                counter8++;
                *(arr8+i)=data[i].get_cnic();
            }
        }

        if(cnic>=1000000000000 && cnic<2000000000000)
        {
            for(int i=0;i<counter;i++)
            {
                if(cnic==*(arr+i))
                {
                    cout<<"Found"<<endl;
                    return true;
                }
            }
        }
        else if(cnic>=2000000000000 && cnic<3000000000000)
        {
            for(int i=0;i<counter2;i++)
            {
                if(cnic==*(arr2+i))
                {
                    cout<<"Found"<<endl;
                    return true;
                }
            }
        }
        else if(cnic>=3000000000000 && cnic<4000000000000)
        {
            for(int i=0;i<counter3;i++)
            {
                if(cnic==*(arr3+i))
                {
                    cout<<"Found"<<endl;
                    return true;
                }
            }
        }
        else if(cnic>=4000000000000 && cnic<5000000000000)
        {
            for(int i=0;i<counter4;i++)
            {
                if(cnic==*(arr4+i))
                {
                    cout<<"Found"<<endl;
                    return true;
                }
            }
        }
        else if(cnic>=5000000000000 && cnic<6000000000000)
        {
            for(int i=0;i<counter5;i++)
            {
                if(cnic==*(arr5+i))
                {
                    cout<<"Found"<<endl;
                    return true;
                }
            }
        }
        else if(cnic>=6000000000000 && cnic<7000000000000)
        {
            for(int i=0;i<counter6;i++)
            {
                if(cnic==*(arr6+i))
                {
                    cout<<"Found"<<endl;
                    return true;
                }
            }
        }
        else if(cnic>=7000000000000 && cnic<8000000000000)
        {
            for(int i=0;i<counter7;i++)
            {
                if(cnic==*(arr7+i))
                {
                    cout<<"Found"<<endl;
                    return true;
                }
            }
        }
        else if(cnic>=8000000000000 && cnic<9000000000000)
        {
            for(int i=0;i<counter8;i++)
            {
                if(cnic==*(arr8+i))
                {
                    cout<<"Found"<<endl;
                    return true;
                }
            }
        }

        cout<<"Not found"<<endl;
        return false;
        
        
        
        

        // for(int i = 0; i < counter; i++)
        // {
        //     cout << *(arr + i) << endl;
        // }


        // for(int i=0;i<11000;i++)
        // {
        //     cout<<data[i].get_cnic()<<endl;
        // }

        // cout<<"Counter == "<<counter<<endl;
        // cout<<"Counter2 == "<<counter2<<endl;
        
        // cout<<"Printing the cnic with ones only "<<endl;

        // for(int i=0;i<counter;i++)
        // {
        //     cout<<arr[i]<<endl;
        // }

        // cout<<"Completed the printing work "<<endl;

        // below code is the correxct one

        // if(data[5500].get_cnic()>cnic)
        // {
        //     for(int i=5500;i<11000;i++)
        //     {
        //         if(cnic==data[i].get_cnic())
        //         {
        //             cout<<"Found"<<endl;
        //             return true;
        //         }
        //     }
        // }
        // else if(cnic==data[5500].get_cnic())
        // {
        //     cout<<"Found"<<endl;
        //     return true;
        // }
        // else if(cnic<data[5500].get_cnic())
        // {
        //     for(int i=0;i<5500;i++)
        //     {
        //         if(cnic==data[i].get_cnic())
        //         {
        //             cout<<"Found"<<endl;
        //             return true;
        //         }
        //     }
        // }
        // cout<<"Not found "<<endl;
        // return false;
    }
};
bool compare_CNIC(Customers a, Customers b)
{
    return a.get_cnic() < b.get_cnic();
}
int main()
{
    Customers data[11000];

    random_device rd;
    mt19937_64 gen(rd());
    uniform_int_distribution<long long> dis(1000000000000, 9999999999999);

    for (int i = 0; i < 11000; i++)
    {
        data[i].set_cnic(dis(gen));
        data[i].set_name("John Doe");
        data[i].set_address("123 Main St");
    }

    // for (int i = 0; i < 11000; i++)
    // {
    //     cout << "Customer " << i + 1 << ":" << endl;
    //     cout<<"cnic = "<<data[i].get_cnic()<<endl;
    //     data[i].get_name();
    //     data[i].get_address();
    //     cout << "--------------------" << endl;
    // }
    bool found = false;
    cout << "Enter the cnic number = ";
    long long num;
    cin >> num;

    cout << "Press 1 to search array" << endl;
    cout << "Press 2 to search dictionary" << endl;
    int choice;
    cin >> choice;

    auto start = chrono::high_resolution_clock::now();
    if (choice == 1)
    {
        for (int i = 0; i < 11000; i++)
        {
            // cout<<data[i].search_linear(num)<<endl;
            if (data[i].search_linear(num))
            {
                found = true;
                break;
            }
        }
    }
    else if (choice == 2)
    {
        sort(data, data + 11000, compare_CNIC);
        // for(int i=0;i<11000;i++)
        // {
        //     found = data[i].search_binary(data, num);
        // }   
        found = data[1].search_binary(data,num);
    }
    auto end = chrono::high_resolution_clock::now(); // Stop the timer
    chrono::duration<double> duration = end - start;

    if (found)
    {
        cout << "CNIC found." << endl;
    }
    else
    {
        cout << "CNIC not found." << endl;
    }

    cout << "Search took " << duration.count() << " seconds." << endl;

    return 0;
}
