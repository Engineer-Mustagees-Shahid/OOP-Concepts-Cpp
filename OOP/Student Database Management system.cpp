#include<iostream>
#include<string>
using namespace std;

class Student{
	
	public:
		string name;
		string roll_no;
		int *marks;
		int num_of_subjects;
		
		Student()
		{
		   num_of_subjects=0;
		   marks=NULL;
		}
		
	void input_data()
	{
		cout<<" Enter the name of the Student : ";
		cin.ignore();
		getline(cin,name);
		cout<<" Enter the roll no of the Student : ";
		cin>>roll_no;
		cout<<" Enter the total number of the subjects : ";
		cin>>num_of_subjects;
		delete [] marks;
		marks=new int [num_of_subjects];
		for(int i=0; i<num_of_subjects; i++)
		{
			cout<<" Enter the marks of "<<i+1<<" Subject : ";
			cin>>marks[i];
		}
	}
	
	void display_data()
	{
		cout<<" Name of the student is : "<<name<<endl;
		cout<<" Roll no of the Student is : "<<roll_no<<endl;
		for(int i=0; i<num_of_subjects; i++)
		{
			cout<<" Marks of the student in "<<i+1<<" Subject is : "<<marks[i]<<endl;
		}
		cout<<endl;	
	}
	
	int total_marks()
	{
		int total_marks=0;
		for(int i=0; i<num_of_subjects; i++)
		{
			total_marks+=marks[i];
		}
		
		return total_marks;
	}
	
	float average_marks()
	{
		if(num_of_subjects==0)
		{
			return 0;
		}
		float average=total_marks() / num_of_subjects;
		return average;
	}
	
	~ Student()
	{
		delete [] marks;
	}
	
};

class Student_database{
	
	private:
	 
	    int count;
	    int capacity;
	    Student *students;
	       
	public:
		
		Student_database(int max_students)
		{
			count=0;
			capacity=max_students;
			students=new Student[capacity];
		}
		
	void add_student()
	{
		if(count<capacity)
		{
			students[count].input_data();
			count++;
		}
		
		else 
		    cout<<endl<<" Database is Full ! "<<endl;
	}
	
	void display_all_students_data()
	{
		if(count==0)
		{
			cout<<endl<<" No Student Record Found ! "<<endl;
		}
		
		else
		    for(int i=0; i<count; i++)
		    {
		    	students[i].display_data();
			}
	}
	
	void diplay_average_of_all_students()
	{
		if(count==0)
		{
			cout<<endl<<" No Student Record Found ! "<<endl;
		}
		
		else 
		    for(int i=0; i<count; i++)
		    {
		    	cout<<endl<<" The Average Marks of the "<<students[i].name<<" is : ";
		    	cout<<students[i].average_marks()<<endl;
			}
	}
	
	void find_topper()
	{
		int toper_index=0;
		
		if(count==0)
		{
			cout<<endl<<" No Student Record Found ! "<<endl;
		}
		
	    else 
		{		
	      	for(int i=1; i<count; i++)
		    {
			    if(students[i].average_marks() > students[toper_index].average_marks())
			    toper_index=i;
		    }
	   
	    cout<<endl<<" The Topper of the Class is : "<<students[toper_index].name<<"("<<students[toper_index].roll_no<<")"<<" with average of "<<students[toper_index].average_marks()<<"."<<endl;
	   }
	}
	
	~Student_database()
	{
		delete [] students;
		students=NULL;
	}
	
};

int main()
{
	cout<<"\n----------------------------------------------WELCOME IN STUDENT DATABASE MANAGEMENT SYSTEM--------------------------------------------------"<<endl;
	cout<<"\n------------------------------------------------------------------ *_* ----------------------------------------------------------------------"<<endl;
	int max_students;
	cout<<endl<<" Enter maximum number of the students in the Class is : ";
	cin>>max_students;
	Student_database database(max_students);
	int choice;
do{
	
	cout<<endl<<"--------------------------------------------------------------- Display Info for Manuplation -----------------------------------------"<<endl;
	cout<<"\n 1. To Add Detail of Student Press 1 and Enter "<<endl;
	cout<<"\n 2. To Display all student records Press 2 and Enter "<<endl;
	cout<<"\n 3. To Calculate and display the average marks of each student Press 3 and Enter "<<endl;
	cout<<"\n 4. To Find the student with the highest total marks (Topper) Press 4 and Enter "<<endl;
	cout<<"\n 5. To Exit from DataBase Management system Press 5 and Enter "<<endl;
	cout<<"\n-----------------------------------------------------------------------Chose?*_*?-----------------------------------------------------------"<<endl;
	cout<<"\n Enter Your Choice : ";
	cin>>choice;
	cout<<endl;
	
	switch(choice)
	{
		case 1:
			database.add_student();
			break;
		case 2:
			database.display_all_students_data();
			break;
		case 3:
			database.diplay_average_of_all_students();
			break;
		case 4:
			database.find_topper();
			break;
		case 5:
			cout<<endl<<" Exiting ! "<<endl;
			break;
		default:
			cout<<endl<<" Enter the valid choice : "<<endl;
	}
		
}while(choice!=5);

	return 0;
}
