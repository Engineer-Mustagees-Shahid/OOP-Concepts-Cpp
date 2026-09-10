#include<iostream>
using namespace std;

int *resize_array(int *old_array, int old_size, int new_size) 
{
    
    int* new_array = new int[new_size];

    for (int i=0; i<old_size; i++) 
	{
        new_array[i]=old_array[i];
    }

    delete[] old_array;

    return new_array;
}

int main() {
    int size = 3;
    int *arr= new int[size] {1, 2, 3}; 

    cout << "Old Array: ";
    for (int i=0; i<size; i++) 
	{
        cout<<arr[i] << " ";
    }
    cout<<endl;

    int new_size =5;
    arr = resize_array(arr, size, new_size);

    for (int i=size; i<new_size; i++) 
	{
        arr[i]=0; 
    }

    cout << "New Resized Array: ";
    
    for (int i=0; i<new_size; i++) 
	{
        cout<<arr[i]<< " ";
    }
    cout<<endl;

    delete[] arr;
    arr = NULL;

    return 0;
}
