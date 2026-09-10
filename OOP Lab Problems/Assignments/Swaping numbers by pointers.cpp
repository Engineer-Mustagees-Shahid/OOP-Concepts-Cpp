#include<iostream>
using namespace std;

void swaping(int*, int*);

int main()
{
	int *a=new int,*b=new int;
	cout<<" Enter two numbers :";
	cin>>*a>>*b;
	swaping(a,b);
	cout<<" Numbers after swpping are : "<<*a<<" "<<*b;
	delete a;
	delete b;
	a=NULL;
	b=NULL;
	
	return 0;
}

void swaping(int *x, int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
	
}