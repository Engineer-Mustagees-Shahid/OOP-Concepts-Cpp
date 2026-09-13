#include<iostream>
using namespace std;

void addition(int**,int,int);

int main()
{
	int rows,cols;
	cout<<" Enter the number of the rows : ";
	cin>>rows;
	cout<<" Enter the number of the cols : ";
	cin>>cols;
	int **arr1= new int *[rows];
	
	for (int i=0; i<rows; i++)
	{
		arr1[i]= new int [cols];
	}
	cout<<" Enter the values of first Matrix : "<<endl;
	
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
		{
		 cin>>*(*(arr1 + i ) + j );
		}	
    }
    
    addition(arr1,rows,cols);
    
    for (int i=0;i<rows;i++)
    {
    	delete [] arr1[i];
    	arr1[i]=NULL;
	}
	
	delete [] arr1;
	arr1=NULL;
    
    
	return 0;
}

void addition(int **arr1, int rows, int cols)
{
	int **arr2=new int *[rows];
	
	for (int i=0; i<rows; i++)
	{
		arr2[i]= new int [cols];
	}
	
	cout<<" Enter the values of the 2nd Matrice : "<<endl;
	
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols; j++)
		{
			cin>>*(*(arr2+i)+j);
		}
	}
	
	cout<<" Addition of two matrices are : "<<endl;
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
		{
			cout<<*(*(arr1 + i) + j) + *(*(arr2 + i) + j)<<"\t";
		}
		cout<<endl;
	}
	
	 for (int i=0;i<rows;i++)
    {
    	delete [] arr2[i];
    	arr2[i]=NULL;
	}
	
	delete [] arr2;
	arr2=NULL;
	
}