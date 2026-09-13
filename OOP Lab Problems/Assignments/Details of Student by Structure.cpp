#include<iostream>
using namespace std;

struct Student{
	
	string name;
	string roll_no;
	int marks;
};

int main()
{
	int n;
	cout<<" Enter the number of students : ";
	cin>>n;
	Student *stu;
	stu=new Student[n];
	
	cout<<endl<<" -------------------------Details of Students in Class -------------------"<<endl<<endl;
	cin.ignore();
	for(int i=0; i<n; i++)
	{
	   cout<<endl<<" ----------------------Detail of "<<i+1<<" Student is :- --------------"<<endl<<endl;
	   cout<<endl<<" Enter the name of the "<<i+1<<" student : ";
	   getline(cin,stu[i].name);
	   cout<<endl<<" Enter the Roll no of the "<<i+1<<" student : ";
	   getline(cin,stu[i].roll_no);
	   cout<<endl<<" Enter the marks of the "<<i+1<<" student : ";
	   cin>>stu[i].marks;
	   cin.ignore();
	   cout<<endl;
	}
	cout<<endl<<endl;
	cout<<endl<<"----------------------------- Deatils of the Students are : ------------------------------"<<endl<<endl;
	for(int i=0; i<n; i++)
	{
	  	cout<<endl<<" Name of the "<<i+1<<" student : "<<stu[i].name<<endl;
	  	cout<<endl<<" Roll No of the "<<i+1<<" student : "<<stu[i].roll_no<<endl;
	  	cout<<endl<<" Marks of the "<<i+1<<" student : "<<stu[i].marks<<endl;
	  	cout<<endl<<"---------------------------------";
	}
    
	delete [] stu;
	stu=NULL;
	
	
	return 0;
}