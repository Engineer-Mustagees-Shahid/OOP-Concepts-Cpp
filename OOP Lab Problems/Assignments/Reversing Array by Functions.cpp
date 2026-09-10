#include<iostream>
using namespace std;

void reversing_array(int *,int);

int main()
{
	int size;
	cout<<" Enter the size of the array : ";
	cin>>size;
	int *arr=new int [size];
	cout<<" Enter the elements of the array : ";
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	
	reversing_array(arr,size);
	
	cout<<" Elements of the array after swapping : ";
	
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	
	delete [] arr;
	arr=NULL;

	return 0;
}

void reversing_array(int *arr, int size)
{
	for (int i=0;i<size/2;i++)
	{
		int temp=arr[i];
		arr[i]=arr[size-i-1];
		arr[size-i-1]=temp;	
	}
}