#include<iostream>

using namespace std;

template <typename T>

T linear_search(T arr[3][4])
{
	//cout<<"Hello"<<endl;
	cout<<"Enter a number to linearly search ? .... ";
	int num;
	cin>>num;

	for(int i=0;i<3;i++)
	{
		//cout<<"Outer "<<endl;
		for(int j=0;j<4;j++)
		{
			//cout<<"Inner"<<endl;
			//cout<<arr[i][j]<<" ";
			if(num == arr[i][j])
			{
				cout<<"Found"<<endl;
				return true;
			}
		}
		//cout<<endl;
	}
	cout<<"Not found"<<endl;
	return false;
}

template <typename T>


T binary_search(T arr[4][4])
{

	int one[16];

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			//cout<<arr2[i][j]<<" ";
			one[i*4 + j] = arr[i][j];
		}
		//cout<<endl;
	}

	/*for(int i=0;i<16;i++)
	{
		cout<<one[i]<<" , ";
		//cout<<endl;
	}*/
	//cout<<endl;
	cout<<endl;
	int temp;

	for(int i=0;i<16;i++)
	{
		for(int j=0;j<16-i;j++)
		{
			if(one[j]>one[j+1])
			{
				temp = one[j];
				one[j] = one[j+1];
				one[j+1] = temp;
			}
		}
	}

	/*for(int i=0;i<16;i++)
	{
		cout<<one[i]<<" , ";
		//cout<<endl;
	}*/
	//cout<<endl;
	cout<<"Enter a number to apply binary search ? .... ";
	int num;
	cin>>num;
	//cout<<"arr[8] = "<<one[8]<<endl;
	if(num>one[8])
	{
		for(int i=8;i<16;i++)
		{
			if(num==one[i])
			{
				cout<<"Found"<<endl;
				return true;
			}
		}
	}
	else if(num==one[8])
	{
		cout<<"Found"<<endl;
		return true;
	}
	else if(num<one[8])
	{
		for(int i=0;i<8;i++)
		{
			if(num==one[i])
			{
				cout<<"Found"<<endl;
				return true;
			}
		}
	}
	cout<<"Not found "<<endl;
	return false;
}

int main()
{

	int arr[3][4] = {{12,43,66,78}, {34,21,72,81}, {7,13,2,59}};
	int arr2[4][4] = {{10,20,30,40}, {15,25,35,45}, {27,29,37,48}, {32,33,39,50}};
	cout<<"Press 1 for linear search "<<endl;
	cout<<"Press 2 for binary search "<<endl;
	int choice;
	cin>>choice;

	if(choice == 1)
	{
		linear_search(arr);
	}
	else if(choice == 2)
	{
		binary_search(arr2);
	}
	

	/*for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout<<arr2[i][j]<<" ";
		}
		cout<<endl;
	}*/


	return 0;
}
