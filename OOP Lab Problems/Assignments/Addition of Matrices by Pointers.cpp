#include<iostream>
using namespace std;

void addition_matrices(int *,int*,int,int);

int main()
{
	int rows,cols;
	cout<<" Enter the number of rows : ";
	cin>>rows;
	cout<<" Enter the number of coloumns : ";
	cin>>cols;
	int *matrix_A=new int[rows*cols];
	int *matrix_B=new int [rows*cols];
	cout<<" Enter the elements of the Matrix A : "<<endl;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cin>>*(matrix_A+i * cols+j);
		}
	}
	cout<<" Enter the elements of the Matrix B : "<<endl;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			cin>>*(matrix_B+i * cols+j);
		}
	}
	addition_matrices(matrix_A,matrix_B,rows,cols);
	delete matrix_A;
	delete matrix_B;
	matrix_A=NULL;
	matrix_B=NULL;
	
	return 0;
}

void addition_matrices(int *matrix_A, int *matrix_B, int rows, int cols)
{
	int *matrix_C= new int [rows*cols];
	cout<<" Addition of Matrix A and B is : "<<endl;
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
		{
			cout<<*(matrix_A+i * cols+j) + *(matrix_B+i * cols+j)<<" ";
		}	
		cout<<endl;
	}
	
}