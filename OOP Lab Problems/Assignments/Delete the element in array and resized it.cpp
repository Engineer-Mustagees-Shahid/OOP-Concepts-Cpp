#include <iostream>
using namespace std;

int main() 
{

    int size=4;
    int *arr=new int[size];


    for (int i=0; i<size; i++)
	{
        arr[i]=i+1;
    }


    cout<< " Original array: ";
    for (int i=0; i<size; i++) 
	{
        cout<<arr[i]<< " ";
    }
    cout<<endl;


    int new_size=6;
    int *new_arr=new int[new_size];


    for (int i=0; i<size; i++) 
	{
        new_arr[i]=arr[i];
    }


    for (int i=size; i<new_size; i++) 
	{
        new_arr[i]=0; 
    }


    delete[] arr;


    arr=new_arr;
    size=new_size;


    cout << " Resized array: ";
    
    for (int i=0; i<size; i++) 
	{
        cout<<arr[i]<< " ";
    }
    cout<<endl;


    delete[] arr;
    arr=NULL;

    return 0;
}
