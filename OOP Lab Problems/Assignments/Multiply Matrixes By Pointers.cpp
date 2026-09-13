#include<iostream>
using namespace std;


int **create_matrix(int rows, int cols)
 {
    int **matrix = new int *[rows];
    for (int i = 0; i < rows; i++) 
	{
        matrix[i] = new int[cols];
    }
    return matrix;
}


int **multiply_matrices(int **matrix_A, int **matrix_B, int rows_A, int cols_A, int cols_B)
 {
    int **matrix_C = create_matrix(rows_A, cols_B);

    for (int i=0; i<rows_A; i++) 
	{
        for (int j=0; j<cols_B; j++) 
		{
            matrix_C[i][j] = 0;  
            for (int k=0; k<cols_A; k++) 
			{
                matrix_C[i][j] += matrix_A[i][k] * matrix_B[k][j];
            }
        }
    }
    return matrix_C;
}

int main() 
{
    int rows_A, cols_A, rows_B, cols_B;

    cout<<"Enter rows and columns for Matrix A: ";
    cin>>rows_A>>cols_A;


    cout<< "Enter rows and columns for Matrix B: ";
    cin>>rows_B>>cols_B;


    if (cols_A != rows_B) 
	{
        cout << "Matrices cannot be multiplied. Number of columns in A must be equal to number of rows in B.\n";
        return 0;
    }

    int **matrix_A = create_matrix(rows_A, cols_A);
    int **matrix_B = create_matrix(rows_B, cols_B);

    cout << "Input Matrix A:"<<endl;
    for(int i=0; i<rows_A; i++)
    {
    	for(int j=0; j<cols_A; j++)
    	{
    		cin>>matrix_A[i][j];
		}
	}

    cout << "Input Matrix B:"<<endl;
     for(int i=0; i<rows_B; i++)
    {
    	for(int j=0; j<cols_B; j++)
    	{
    		cin>>matrix_B[i][j];
		}
	}

    int **matrix_C = multiply_matrices(matrix_A, matrix_B, rows_A, cols_A, cols_B);

    cout<<endl<<" Matrix A x B is : "<<endl;

    for(int i=0; i<rows_A; i++)
    {
    	for (int j=0; j<cols_B; j++)
    	{
    		cout<<matrix_C[i][j]<<"\t";
		}
		cout<<endl;
	}

   
    for (int i=0; i<rows_A; i++) 
	{
        delete[] matrix_A[i];
        matrix_A[i]=NULL;
    }
    delete[] matrix_A;
    matrix_A=NULL;

    for (int i=0; i<rows_B; i++) 
	{
        delete[] matrix_B[i];
        matrix_B[i]=NULL;
    }
    delete[] matrix_B;
    matrix_B=NULL;
   
       for (int i=0; i<rows_A; i++) 
	{
        delete[] matrix_C[i];
        matrix_C[i]=NULL;
    }
    delete[] matrix_C;
    matrix_C=NULL;
   

    return 0;
}
