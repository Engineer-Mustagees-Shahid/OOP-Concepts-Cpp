#include<iostream>
using namespace std;

struct Book{
	
	string title;
	string author;
	float price;
};

void Input_data(struct Book *bk, int n)
{
	cin.ignore();
	
	for(int i=0; i<n; i++)
	{
		cout<<endl<<"-------------------------Details of "<<i+1<<" book is : "<<"-----------------------"<<endl<<endl;
		cout<<" The title of "<<i+1<<" book is : ";
		getline(cin,bk[i].title);
		cout<<endl;
		cout<<" The author of "<<i+1<<" book is : ";
		getline(cin,bk[i].author);
		cout<<endl;
		cout<<" The price of "<<i+1<<" book is : $ ";
		cin>>bk[i].price;
		cin.ignore();
		cout<<endl;
	}
	cout<<endl<<endl;
	
}

void display_data(struct Book *bk, int n)
{
	cout<<endl<<"-----------------------------Deatils of the book are : ------------------------------"<<endl<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<" The title of "<<i+1<<" book is : "<<bk[i].title<<endl<<endl;
		cout<<" The author of "<<i+1<<" book is : "<<bk[i].author<<endl<<endl;
		cout<<" The price of "<<i+1<<" book is : $ "<<bk[i].price<<endl<<endl;
		cout<<"----------------------------------------------------"<<endl;
	}
	cout<<endl<<endl;
}

void display_most_expensive_book(struct Book *bk, int n)
{
	int max=0;
	for(int i=1; i<n; i++)
	{
		if(bk[i].price>bk[max].price)
		{
			max=i;
		}
	}
	
	cout<<"The Most Expensive Book is ! : "<<endl<<endl;
	cout<<" The title of most Expensive book is : "<<bk[max].title<<endl<<endl;
	cout<<" The author of most expensive book is : "<<bk[max].author<<endl<<endl;
	cout<<" The price of mot expensive book is : $ "<<bk[max].price<<endl<<endl;
}

void sorted_book(struct Book *bk, int n)
{
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(bk[i].title>bk[j].title)
			{
				Book temp=bk[i];
				bk[i]=bk[j];
				bk[j]=temp;
			}
		}
	}
	
	cout<<" Books are Sorted Alphabhatically ! "<<endl<<endl<<endl;
	
}


int main()
{
	int n;
	cout<<endl<<" Enter the Number of Books : ";
	cin>>n;
	Book *bk;
	bk=new Book[n];
	Input_data(bk,n);
	display_data(bk,n);
	display_most_expensive_book(bk,n);
	sorted_book(bk,n);
	cout<<" After Sorted Books Alphabatecally Books Arranged in : "<<endl<<endl;
	display_data(bk,n);
	delete [] bk;
	bk=NULL;
	
	return 0;
}