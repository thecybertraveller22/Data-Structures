// 22i-1552_Lab11 : This file contains the 'main' function. Program execution begins and ends there.
//  This code is for -------------------------------- {MAX HEAP} --------------------------------
//  Sort wala fucntion sorts the array in ascending order ie: { MAX HEAP in ascending order }

#include<iostream>

using namespace std;

class Heap
{
public:
	int* arr;
	int* new_arr;
	int capacity;
	int size;
	//int size2;

	Heap()
	{
		capacity = 6;
		arr = new int [capacity];
		new_arr = new int[capacity];
		size = 0;
		//size2 = 0;
	}

	void insert(int value)
	{
		if (size == capacity)
		{
			cout << "Cannot insert in the heap as its full" << endl;
			return;
		}
		size++;
		int index = size - 1;
		arr[index] = value;

		for (int i = (size / 2) - 1; i >= 0; i--)
		{
			Heapify(i);
		}
			
	}

	void Heapify(int i)
	{
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < size && arr[left] > arr[largest])
		{
			largest = left;
		}

		if (right < size && arr[right] > arr[largest])
		{
			largest = right;
		}

		if (largest != i)
		{
			swap(arr[i], arr[largest]);
			Heapify(largest);
		}
	}

	

	int Remove() 
	{
		if (size == 0)
		{
			cout << "Heap is empty " << endl;
			return -1;
		}
		int root = arr[0];
		arr[0] = arr[size-1];
		size--;

		for (int i = (size / 2) - 1; i >= 0; i--)
		{
			Heapify(i);
		}
		return root;
	}

	void display()
	{
		if (size == 0)
		{
			cout << "Heap is empty" << endl;
		}

		for (int i = 0; i <= size - 1; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	

	void clear()
	{
		delete[] arr;
		arr = nullptr;
		size = 0;
		capacity = 0;
	}

	bool isEmpty()
	{
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void SortArray()
	{	
		///Heap h1;
		int s = size;
		

		/*for (int i = 0; i < capacity; i++)
		{
			cout << "Enter number = ";
			s++;
			int num;
			cin >> num;
			h1.insert(num);
		}*/
		
		
		//cout << "-----------------------------------" << endl;
		//cout << "After heapify" << endl;
		
		//h1.display();
		//cout << "-----------------------------------" << endl;
		
		// cout << "-----------------------------------" << endl;
		cout << "After Sorting " << endl;
		
		int root;
		//cout << "Here" << endl;
		for (int i = s-1; i >= 0; i--)
		{
			//cout << "hello" << endl;
			root = Remove();
			new_arr[i] = root;
		}
		//cout << "Hre2" << endl;
		for (int i = 0; i < s; i++)
		{
			//cout << "skhdbask" << endl;
			cout << new_arr[i] << " ";
		}
		cout << endl;
		//cout << "-----------------------------------" << endl;
		//cout << root << endl;

	}
};

int main()
{
	Heap h;
	//h.insert(50);
	//h.insert(67);
	//h.insert(77);
	//h.insert(10);
	//h.insert(550);
	//h.insert(900);
	////h.insert(1);
	//h.display();
	//h.Remove();
	//cout << "******************" << endl;
	//h.display();
	//h.clear();
	//cout << "******************" << endl;
	//h.display();
	int choice = 99999;
	while (choice != 0)
	{
		cout << "1. Insert" << endl;
		cout << "2. SortArray" << endl;
		cout << "3. Remove" << endl;
		cout << "4. Display" << endl;
		cout << "5. Clear" << endl;
		cout << "0. Exit" << endl;
		cin >> choice;
		if (choice == 1)
		{
			cout << "-----------------------------------" << endl;
			h.insert(50);
			h.insert(67);
			h.insert(77);
			h.insert(10);
			h.insert(550);
			h.insert(900);
			cout << "-----------------------------------" << endl;
		}
		else if (choice == 2)
		{
			cout << "-----------------------------------" << endl;
			h.SortArray();
			cout << "-----------------------------------" << endl;
		}
		else if (choice == 3)
		{
			cout << "-----------------------------------" << endl;
			h.Remove();
			cout << "-----------------------------------" << endl;
		}
		else if (choice == 4)
		{
			cout << "-----------------------------------" << endl;
			h.display();
			cout << "-----------------------------------" << endl;
		}
		else if (choice == 5)
		{
			cout << "-----------------------------------" << endl;
			h.clear();
			cout << "-----------------------------------" << endl;
		}
		else if (choice == 0)
		{
			cout << "-----------------------------------" << endl;
			cout << "GoodBye................" << endl;
			cout << "-----------------------------------" << endl;
		}

	}
	

	cout << "******************" << endl;
	
	cout << "******************" << endl;
	
	return 0;
}