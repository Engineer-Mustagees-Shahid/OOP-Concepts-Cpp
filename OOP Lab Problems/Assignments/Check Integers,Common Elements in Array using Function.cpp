#include<iostream>
using namespace std;
int check_integers(int*,int*,int);
int common_elements(int*,int*,int);
int main()
{
	int size;
	cout<<" Enter the size of the arrays: ";
	cin>>size;
	int *arr_2= new int [size];
	int *arr_1= new int [size];
	cout<<" Enter the elements of the first array :";
	for(int i=0; i<size; i++)
	{
		cin>>arr_1[i];
	}
	cout<<" Enter the elements of the second array :";
    for(int j=0; j<size; j++)
	{
		cin>>arr_2[j];
	}	
	int total_count=check_integers(arr_1,arr_2,size);
	cout<<" "<<total_count<<" integers are placed at same location with the same value in both arrays.";
	int total_common_elements=common_elements(arr_1,arr_2,size);
	cout<<endl<<" "<<total_common_elements<<" common elements in both arrays.";
	delete [] arr_1;
	delete [] arr_2;
	arr_1=NULL;
	arr_2=NULL;
	
	return 0;
}

int check_integers(int *arr_1, int *arr_2, int size)
{
	int count=0;
	for(int i=0;i<size;i++)
	{
		if(arr_1[i]==arr_2[i])
	   {
		   	count++;
		}
	}
return count;		
}

int common_elements(int *arr_1, int *arr_2, int size)
{
	int common=0;
	for (int i=0;i<size;i++)
	{
		int already_counted_in_itself_array=0;
		
		for(int j=0;j<i;j++)
		{
			if(arr_1[i]==arr_1[j])
		  {
			already_counted_in_itself_array=1;
			break;
		   }
		
		}
		
		if (!already_counted_in_itself_array) 
		{
            for (int j=0;j<size;j++) 
			{
                if (arr_1[i]==arr_2[j]) 
				{
                    common++;
                    break; 
                }
            }
       }
	}
	return common;
}