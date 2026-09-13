#include<iostream>
using namespace std;

struct Book{
	
	string title;
	string author;
	double price;
};

int main()
{
	int total_no_of_books;
	cout<<endl<<" Enter the total no of books in libirary :  ";
	cin>>total_no_of_books;
	Book bk[total_no_of_books];
	cout<<endl<<"-----------------------------Write Deatils of the book are : ------------------------------"<<endl<<endl;
	cin.ignore();
	
	for(int i=0; i<total_no_of_books; i++)
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
	cout<<endl<<"-----------------------------Deatils of the book are : ------------------------------"<<endl<<endl;
	
	for(int i=0; i<total_no_of_books; i++)
	{
		if(bk[i].price>500)
		{
		cout<<" The title of "<<i+1<<" book is : "<<bk[i].title<<endl<<endl;
		cout<<" The author of "<<i+1<<" book is : "<<bk[i].author<<endl<<endl;
		cout<<" The price of "<<i+1<<" book is : $ "<<bk[i].price<<endl<<endl;
		}
	}
	
   return 0;	
}