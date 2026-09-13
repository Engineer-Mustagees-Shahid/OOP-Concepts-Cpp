#include<iostream>
using namespace std;


class Address{
	
	private:
			
		string city;
		string street;
		
	public:
		
		Address(string city, string street)
		{
			this->city=city;
			this->street=street;
			cout<<" Addrees at "<<street<<" no and "<<city<<" is Createtd "<<endl;
		}
		
		~Address()
		{
			cout<<" Addrees at "<<street<<" no and "<<city<<" is Destroyed "<<endl;
		}
		
		void display()
		{
			cout<<" Address : "<<street<<" and "<<city<<endl;
		}

};


class Student{
	
	private:
		
		string name;
		Address *address;
		
	public:
		
		Student(string n, Address *addr)
		{
			name=n;
			address=addr;
			cout<<" Student "<<name<<" is created "<<endl;
		}
		
		~Student()
		{
			cout<<" Student "<<name<<" is destroyed. "<<endl;
		}
		
		void display()
		{
			cout<<" Student name : "<<name<<endl;
			address->display();
		}
	
};


int main()
{
	Address *addr_1= new Address(" Peshawar ", " University Road");
	Student s_1("Ali",addr_1);
	s_1.display();
	
	cout<<" Address still exist but Student is destroyed. "<<endl;
	addr_1->display();
	
	delete addr_1;
	
	return 0;
}