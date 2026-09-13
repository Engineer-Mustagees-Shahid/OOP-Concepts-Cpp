#include<iostream>
using namespace std;

struct Employee{
	
	string name;
	string id;
	double salary;
};

int main()
{
	Employee emp;
	Employee *ptr=&emp;
	
	cout<<" Enter the name of the Employee : ";
	getline(cin,ptr->name);
	cout<<endl;
	cout<<" Enter the ID of the Employee : ";
	getline(cin,ptr->id);
    cout<<endl;
	cout<<" Enter the Salary of the Employee : ";
	cin>>ptr->salary;
	cout<<endl;
	cout<<endl<<endl<<"------------------ Employee Deatils : --------------------"<<endl<<endl;
	
	cout<<" The Name of the Employee is : "<<ptr->name<<endl<<endl;
	cout<<" The ID of the Employee is : "<<ptr->id<<endl<<endl;
	cout<<" The Salary of the Employee is : "<<ptr->salary<<endl<<endl;
	
	return 0;
}