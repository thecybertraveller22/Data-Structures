#include <iostream>
#include<math.h>

using namespace std;

int main()
{
    int n = 5;
    int d = 0;

    for (int a = 1; a < n; a++)
    {
        for (int b = 1; b < n; b++)
        {
            for (int c = 1; c < n; c++)
            {
                d = cbrt(pow(a, 3) + pow(b, 3) - pow(c, 3));

                if (pow(a, 3) + pow(b, 3) == pow(c, 3) + pow(d, 3))
                {
                    cout << "a = " << a << endl;
                    cout << "b = " << b << endl;
                    cout << "c = " << c << endl;
                    cout << "d = " << d << endl;
                }
            }
        }
    }
    return 0;
}

