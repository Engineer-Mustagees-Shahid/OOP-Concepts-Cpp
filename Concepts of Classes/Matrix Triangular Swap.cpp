#include<iostream>
using namespace std;

// Function to allocate memory for the matrix
int **Allocate_memory(int &rows, int &cols)
{
	int **matrix=new int*[rows];
	for(int i=0; i<rows;i++)
	{
		matrix[i]= new int[cols];
	}
	return matrix;
}

// Function to take input for the matrix
void Input_matrix(int **matrix, const int rows, const int cols)
{
	cout<<"\n Enter the elements of the matrix : "<<endl;
	for(int i=0; i<rows;i++)
	{
		for(int j=0; j<cols; j++)
		{
			cin>>matrix[i][j];
		}
	}
}

// Function to display the matrix
void display_Matrix(int **matrix, const int &rows, const int &cols)
{
	cout<<"\n Elements of the matrix are : "<<endl;
	for(int i=0; i<rows; i++)
	{
		for(int j=0; j<cols;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

// Function to swap the lower triangular half with the upper triangular half
void swapTriangular(int** matrix, const int& rows, const int& cols) {
    if (rows != cols) {
        cout << "Matrix is not square, swapping not possible." << endl;
        return;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            // Swap elements in lower and upper triangular
            	int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
	   
        }
    }
}

// Main function
int main() {
    int rows, cols;
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    if (rows != cols) {
        cout << "Error: Matrix must be square for triangular swap." << endl;
        return -1;
    }

    // Allocate memory for matrix
    int** matrix = Allocate_memory(rows, cols);

    // Input matrix elements from the user
    Input_matrix(matrix, rows, cols);

    // Display the original matrix
    cout << "Original Matrix:" << endl;
    display_Matrix(matrix, rows, cols);

    // Swap triangular parts
    swapTriangular(matrix, rows, cols);

    // Display the modified matrix
    cout << "Matrix after swapping triangular halves:" << endl;
    display_Matrix(matrix, rows, cols);

    // Free allocated memory
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

