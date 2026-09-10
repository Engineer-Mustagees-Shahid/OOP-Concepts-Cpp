#include<iostream>
#include<string>
using namespace std;

class Student{
	
	public:
		
	string *student_name;
	int *student_age;
	double *marks;
	
	Student(int size)
	{
		student_name= new string [size];
		student_age= new int [size];
		marks= new double [size];
	}
	

	~Student() 
	{
        delete[] student_name;
        delete[] student_age;
        delete[] marks;
    }

	
};

void set_student_details(Student *stu, int size)
{
	for (int i=0; i<size; i++)
	{
		cout<<endl<<" Enter the "<< i+1 <<" Student name : ";
		cin>>stu->student_name[i];
		cout<<endl<<" Enter the age of "<<stu->student_name[i]<<" : ";
		cin>>stu->student_age[i];
		cout<<endl<<" Enter the marks of "<<stu->student_name[i]<<" : ";
		cin>>stu->marks[i];
		cout<<"-----------------------------"<<endl;
	}

}

void display_details(Student *stu, int size)
{
	cout<<endl<<endl<<" Student Details : "<<endl;
	for (int i=0; i<size; i++)
	{
		cout<<endl<<" Name : "<<stu->student_name[i]<<endl;
		cout<<endl<<" Age : "<<stu->student_age[i]<<endl;
		cout<<endl<<" Marks : "<<stu->marks[i]<<endl;
		cout<<"-------------------"<<endl;
	}
	cout<<endl;
}

void check_scholarship_eligibility(Student *stu, int size)
{
	cout<<endl<<" Eligibility Checking : "<<endl<<endl;
	for (int i=0; i<size; i++)
	{
		if(stu->marks[i]>85)
		cout<<" "<<stu->student_name[i]<<" is eligible for Scholarship."<<endl<<endl;;
	}
}



int main()
{
	int size;
	cout<<" Enter the number of students : ";
	cin>>size;
	Student stu(size);
	set_student_details(&stu,size);
	display_details(&stu,size);
	check_scholarship_eligibility(&stu,size);
	
	
	return 0;
}