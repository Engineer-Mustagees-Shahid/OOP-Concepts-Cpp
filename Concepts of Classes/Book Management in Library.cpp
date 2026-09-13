#include<iostream>
using namespace std;


class Book{
	
	private:
		
		string title;
		
	public:
		
		Book(string t)
		{
			title=t;
			cout<<" Book "<<title<<" is Created. "<<endl;
		}
		
		~Book()
		{
			cout<<" Book "<<title<<" is Destroyed. "<<endl;
		}
		
		void display()
		{
			cout<<" Book Title is "<<title<<endl;
		}

};

class Library{
	
	private:
		
		Book **book;
		int count;
	
	public:
		
		Library(string title[], int count)
		{
			this->count=count;
			book=new Book *[count];
			
			for(int i=0; i<count; i++)
			{
				book[i]= new Book(title[i]);
			}
			
			cout<<" Library is Created with "<<count<<" no of Books. "<<endl;
		}
		
		~Library()
		{
			for(int i=0;i<count; i++)
			{
				delete book[i];
			}
			delete[] book;
			
			cout<<" Library is Destroyed beacuse books are destroyed. "<<endl;
		}
		
		void display_books()
		{
			cout<<" Library containing books are : "<<endl;
			
			for(int i=0; i<count; i++)
			{
				book[i]->display();
			}
		}
	
};

int main()
{
	string title[]={"C++ Programming","OOP","PF","Data Structure"};
	int count=sizeof(title)/sizeof(title[1]);
	
	Library lib(title,count);
	lib.display_books();
	
	return 0;
}
