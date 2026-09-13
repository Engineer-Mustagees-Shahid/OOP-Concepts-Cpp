#include<iostream>
using namespace std;

int **create_theter(int,int);
void display_theter(int**,int,int);



int main()
{
	int rows,cols;
	cout<<" Enter total nmber of rows in theter : ";
	cin>>rows;
	cout<<" Enter total number of seats in theter : ";
	cin>>cols;
	int **theter= create_theter(rows,cols);
	
	
	int total_reserved=0;
	char choice;
	
	do{
		display_theter(theter,rows,cols);
		int row,col;
		cout<<endl<<" Enter the row and seat to reserve : ";
		cin>>row>>col;
		if(row>0 && col>0 && col<=cols && row<=rows)
		{
			if(theter[row-1][col-1]==0)
			{
				theter[row-1][col-1]=1;
				total_reserved++;
				cout<<endl<<" Seat is reserved successfully. "<<endl;
			}
			else
			{
			  cout<<endl<<" Seat is already reserved."<<endl;	
			}
		}
		else
		{
			cout<<endl<<endl<<" Invalid Selection."<<endl<<endl;
		}
		
		cout<<endl<<" Do you want to reserve another seat ? ('y' for yess): ";
		cin>>choice;
	
	} while(choice=='y'|| choice=='Y');
	
	display_theter(theter,rows,cols);
	
	cout<<endl<<" Total reserved seats is : "<<total_reserved;
	
	for (int i=0; i<rows; i++)
	{
		delete [] theter[i];
		theter[i]=NULL;
	}
		
		delete [] theter;
		theter=NULL;
		
	
	return 0;
}

int **create_theter(int rows, int cols)
{
	int **display = new int *[rows];
	for(int i=0; i<rows; i++)
	{
		display[i]= new int [cols];
		for(int j=0; j<cols; j++)
		{
			display[i][j]=0;
		}
	}
	
   return display;
}

void display_theter(int **theter, int rows, int cols)
{
	cout<<endl<<" Seating Chart of theter is : "<<endl<<endl;
	for (int i=0; i<rows; i++)
	{
		for (int j=0; j<cols; j++)
		{
			cout<<theter[i][j]<<"\t";
		}
		cout<<endl;
	}
}