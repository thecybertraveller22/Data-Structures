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
        // cout << "CNIC = " << cnic << endl;
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
        // int left = 0;
        // int right = 11000 - 1;
        // while (left <= right)
        // {
        //     int mid = left + (right - left) / 2;
        //     if (data[mid].get_cnic() == cnic)
        //     {
        //         return true;
        //     }
        //     else if (data[mid].get_cnic() < cnic)
        //     {
        //         left = mid + 1;
        //     }
        //     else
        //     {
        //         right = mid - 1;
        //     }
        // }
        // return false;

        // int left = 0;
        // int right = 11000 - 1;
        // while (left <= right)
        // {
        //     int mid = left + (right - left) / 2;
        //     if (data[mid].get_cnic() == cnic)
        //     {
        //         return true;
        //     }
        //     else if (data[mid].get_cnic() < cnic)
        //     {
        //         left = mid + 1;
        //     }
        //     else
        //     {
        //         right = mid - 1;
        //     }
        // }
        // return false;
        // long long counter1=0;
        // long long counter2=0;
        // long long counter3=0;
        // long long counter4=0;
        // long long counter5=0;
        // long long counter6=0;
        // long long counter7=0;
        // long long counter8=0;

        // for(int i=0;i<11000;i++)
        // {
        //     //cout<<"Hello"<<endl;
            
        //     if(data[i].get_cnic()>=1000000000000 && data[i].get_cnic()<2000000000000)
        //     {
        //         counter1++;
        //     }
        //     else if(data[i].get_cnic()>=2000000000000 && data[i].get_cnic()<3000000000000)
        //     {
        //         counter2++;
        //     }
        //     else if(data[i].get_cnic()>=3000000000000 && data[i].get_cnic()<4000000000000)
        //     {
        //         counter3++;
        //     }
        //     else if(data[i].get_cnic()>=4000000000000 && data[i].get_cnic()<5000000000000)
        //     {
        //         counter4++;
        //     }
        //     else if(data[i].get_cnic()>=5000000000000 && data[i].get_cnic()<6000000000000)
        //     {
        //         counter5++;
        //     }
        //     else if(data[i].get_cnic()>=6000000000000 && data[i].get_cnic()<7000000000000)
        //     {
        //         counter6++;
        //     }
        //     else if(data[i].get_cnic()>=7000000000000 && data[i].get_cnic()<8000000000000)
        //     {
        //         counter7++;
        //     }
        //     else if(data[i].get_cnic()>=8000000000000 && data[i].get_cnic()90000000000000)
        //     {
        //         counter8++;
        //     }
        // }
        // long long *arr1[counter1];
        // for(int i=0;i<counter1;i++)
        // {

        // }

        if(data[5500].get_cnic()>cnic)
        {
            for(int i=5500;i<11000;i++)
            {
                if(cnic==data[i].get_cnic())
                {
                    cout<<"Found"<<endl;
                    return true;
                }
            }
        }
        else if(cnic==data[5500].get_cnic())
        {
            cout<<"Found"<<endl;
            return true;
        }
        else if(cnic<data[5500].get_cnic())
        {
            for(int i=0;i<5500;i++)
            {
                if(cnic==data[i].get_cnic())
                {
                    cout<<"Found"<<endl;
                    return true;
                }
            }
        }
        cout<<"Not found "<<endl;
        return false;
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

    /*for (int i = 0; i < 11000; i++)
    {
        cout << "Customer " << i + 1 << ":" << endl;
        data[i].get_cnic();
        data[i].get_name();
        data[i].get_address();
        cout << "--------------------" << endl;
    }*/
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
