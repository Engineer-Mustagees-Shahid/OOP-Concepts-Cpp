#include<iostream>
using namespace std;

int **transpose(int **,int,int);

int main()
{
	int rows,cols;
	cout<<" enter the number of rows : ";
	cin>>rows;
	cout<<" Enter the number of the coloumns : ";
	cin>>cols;
	int **matrice_1= new int *[rows];
	for(int i=0; i<rows; i++)
	{
		matrice_1[i]= new int[cols];
	}
	
	cout<<" Enter the values of Matrice _1 : "<<endl;
	for( int i=0;i<rows; i++)
	{
		for (int j=0;j<cols; j++)
		{
			cin>>*(*(matrice_1 +i)+j);
		}
	}
	
	int **matrice_2= transpose(matrice_1,rows,cols);
	
	cout<<" Original Matrice _1 before transpose : "<<endl<<endl;
	for( int i=0;i<rows; i++)
	{
		for (int j=0;j<cols; j++)
		{
			cout<<*(*(matrice_1 +i)+j)<<"\t";
		}
		cout<<endl;
	}
	
	cout<<" Transpose of Matrice _1 is : "<<endl<<endl;
	for( int i=0;i<cols; i++)
	{
		for (int j=0;j<rows; j++)
		{
			cout<<*(*(matrice_2 +i)+j)<<"\t";
		}
		cout<<endl;
	}
	
	for (int i=0; i<rows; i++)
	{
		delete [] matrice_1[i];
		matrice_1[i]=NULL;
	}
	delete [] matrice_1;
	matrice_1=NULL;
	
	for (int i=0; i<cols; i++)
	{
		delete [] matrice_2[i];
		matrice_2[i]=NULL;
	}
	delete [] matrice_2;
	matrice_2=NULL;
	
	
	return 0;
}

int **transpose(int **matrice_1, int rows,int cols)
{
	int **matrice_2= new int *[cols];
	for (int i=0; i<cols; i++)
	{
		matrice_2[i]= new int [rows];
	}
	
	
	for(int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
		{
			*(*(matrice_2 + j)+ i)=*(*(matrice_1 + i)+j);
		}
	}
	
	return matrice_2;
}


