// 22i-1552 lab 2 task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void reverse(int array[], int arr_length)
{
	int start = 0;
	int end = arr_length - 1;

	while (start < end)
	{
		int temp = *(array+start);
		*(array + start) = *(array+end);
		*(array + end) = temp;
		start++;
		end--;
	}
	cout << "-------------------" << endl;
	for (int i = 0; i < arr_length; i++)
	{
		cout << *(array + i) << endl;
	}
}


int main()
{
	int len;
	cout << "Enter the size of array = ";
	cin >> len;

	int* arr = new int[len];

	for (int i = 0; i < len; i++)
	{
		cin >> *(arr+i);
	}

	reverse(arr, len);

	return 0;
}

