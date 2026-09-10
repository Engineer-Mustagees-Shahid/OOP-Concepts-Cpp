#include<iostream>

using namespace std;

void swapping(int *arr, int size)
{
	for (int i=0; i<size-1; i+=2)
	{
		int temp=arr[i];
		arr[i]=arr[i+1];
		arr[i+1]=temp;
	}
	
	cout<<" The Modified Array is : "<<endl;
	for (int i=0; i<size; i++)
	{
	    cout<<arr[i]<<" ";
	}
	
}

int main()
{
	int size;
	cout<<" Enter the size of the array : ";
	cin>>size;
	int *arr= new int [size];
	cout<<" Enter the elements of the array : ";
	for (int i=0; i<size; i++)
	{
		cin>>arr[i];
	}

	swapping (arr,size);
	
	delete [] arr ;
	arr=NULL;
	
	return 0;
}