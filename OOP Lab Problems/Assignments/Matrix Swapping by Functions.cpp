#include<iostream>
using namespace std;

void swap(int,int[],int[]);

int main ()
{
	int n,temp;
	
	cout<<"Enter the size of the array : ";
	cin>>n;

	int array_1[n],array_2[n];
	
	cout<<endl<<"Enter the elements of the array A are : ";
	
	for (int i=0; i<n; i++)
	{
		cin>> array_1[i];
	}
	
	cout<<endl<<"Enter the elements of the array B are : ";
	
	for(int i=0; i<n; i++)
	{
		cin>> array_2[i];
	}
	
	 swap(n,array_1,array_2);
	
	
	
	cout<<endl<<endl<<"The elements of array A after swapping are : ";
	
	for (int i=0; i<n; i++)
	{
		cout<<array_1[i]<<" ";
	}
	
	cout<<endl<<endl<<"The elements of array B after swapping are : ";
		
	for (int i=0; i<n; i++)
	{
		cout<<array_2[i]<<" ";
	}
	
	return 0;
}

void swap(int n, int array_1[], int array_2[])
{
	for(int i=0; i<n; i++)
	{
		int temp=array_2[i];
		array_2[i]=array_1[i];
		array_1[i]=temp;
	}
}

