#include<iostream>
using namespace std;

void unique(int,int[]);

int main ()
{
	int arr[25];
	int n=25;
	
	cout<<"Enter the elements of the array : ";
	
	for (int i=0; i<n;i++)
	{
		cin>>arr[i];
	}
	
	unique(n,arr);
	

	return 0;
}

void unique(int n,int arr[])
{
		for (int i=0; i<n;i++)
	{
		int count=0;
		    for (int j=0; j<n;j++)
		     {
		     	if(arr[i]==arr[j])
		     	count++;
		    }
		 if (count==1)
		 cout<<endl<<"The unique elements of the array are : "<<arr[i]<<" ";
	}
}