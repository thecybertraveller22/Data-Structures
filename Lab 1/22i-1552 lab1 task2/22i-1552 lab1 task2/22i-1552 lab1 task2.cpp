// 22i-1552 lab1 task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

template <typename T, typename T2> class Numbers
{
private:
    T A;
    T2 B;

public:
    Numbers(T A1, T2 B1)
    {
        A = A1;
        B = B1;
    }
    T Asquare()
    {
        T result = A * A;
        return result;
    }
    T division()
    {
        if (B != 0)
            return A / B;
        else
            return 0;
    }
};
int main()
{
    Numbers<float,int> num(10.9, 3);
    cout << " A square : " << num.Asquare() << endl;
    cout << " A/B : " << num.division() << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
