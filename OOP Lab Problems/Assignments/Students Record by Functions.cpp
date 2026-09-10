#include<iostream>
#include<string>
using namespace std;

void add_new_student(string names[],int roll_no[],int marks[][3],int &count,int max_students,const int subjects)
{
	if(count<max_students)
	{
		cout<<endl<<"Name of Student :";
		cin>>names[count];
		cout<<endl<<"Enter the student roll no :";
		cin>>roll_no[count];
		
		cout<<endl<<"Enter the marks of the students in three subjects :"<<endl;
		for (int i=0; i<subjects;i++)
		{
		   cin>>marks[count][i];
		   
		       if(marks[count][i]>100 || marks[count][i]<0)
		   {
		            cout<<endl<<endl<<"Enter valid Marks."<<endl;
		   }
		}
		
		count++;
	}
	
	else 
	   cout<<endl<<"Database is full So we cannot add more students."<<endl;
}

void display_records(string names[],int roll_no[],int marks[][3],int count,const int subjects)
{
	if (count==0)
	{
		cout<<endl<<"NO RECORD FOUND!"<<endl;
	}
	else 
	{
		for(int i=0; i<count; i++)
		{
		    cout<<endl<<"Name of Student :"<<names[i]<<endl;
		    cout<<endl<<"Roll No :"<<roll_no[i]<<endl;
		    
		        for(int j=0;j<subjects;j++)
		    {
			    cout<<endl<<"Marks of the subject "<<j+1<<" is :"<<marks[i][j]<<" ";
		   }
		cout<<endl;
	 }
	 cout<<endl;
  }
}

void average_marks(string names[],int roll_no[], int marks[][3],int count,int subjects)
{
	if (count==0)
	{
		cout<<endl<<"NO RECORD FOUND"<<endl;
	}
	else
	 {
	 	for (int i=0; i<count;i++)
		{
		    int total_marks=0;
		    
		        for (int k=0;k<subjects;k++)
		        {
		        	total_marks=total_marks+marks[i][k];
				}
		        
		    float average=(float)(total_marks/subjects);
		    cout<<endl<<"Average marks of the "<<names[i]<<" is :"<<average<<endl;
		}
	}
	
}

void highest_marks(string names[],int roll_no[],int marks[][3],int count,const int subjects)
{
    if(count==0)
    {
    	cout<<endl<<"NO RECORD FOUND"<<endl;
	}
    
    else
    {
     	int highest_total=-1;
	    int student_index=-1;
	
	for (int i=0; i<count; i++)
	{
		int total_marks=0;
	
	         for (int j=0; j<subjects; j++)
	         {
	         	total_marks+=marks[i][j];
			 }
			 
		if (total_marks>highest_total)
		{
			highest_total=total_marks;
			student_index=i;	
		}	
	 }
		cout<<endl<<"Student with highest marks is "<<names[student_index]<<" with roll no "<<roll_no[student_index]<<" and total marks is  "<<highest_total<<endl;
  }	
	
}



int main()
{
	int max_students,choice;
	cout<<endl<<"Enter the total number of students: ";
	cin>>max_students;
	cout<<endl<<endl;
	const int subjects=3;
	int count=0;
	string names[max_students];
	int roll_no[max_students];
	int marks[max_students][subjects];
do{
    cout<<"---------------------------------------------------------------------------------------------Student Management System-------------------------------------------------------------------------------"<<endl<<endl;
	cout<<endl<<endl<<"Add new student records Press (1) And Enter."<<endl<<endl;
	cout<<"Display all students record Press (2) And Enter."<<endl<<endl;
	cout<<"Display Average marks of the students Press(3) And Enter"<<endl<<endl;
	cout<<"Highest total marks Press(4) And Enter"<<endl<<endl;
	cout<<"To exit fromthe Database Press(5) And Enter"<<endl<<endl;
	cout<<"---------------------------------------------------------------------------------------------Student Management System-------------------------------------------------------------------------------"<<endl<<endl<<endl<<endl;
	cout<<endl<<endl<<"Enter your choice :"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			add_new_student(names,roll_no,marks,count,max_students,subjects);
			break;
		case 2:
			display_records(names,roll_no,marks,count,subjects);
			break;
		case 3:
			average_marks(names,roll_no,marks,count,subjects);
			break;
		case 4:
			highest_marks(names,roll_no,marks,count,subjects);
			break;
		case 5:
			return 0;
			break;
		default :
			cout<<endl<<"Enter the valid number.";
		
	}
	
	}while(choice!=5);
	
	return 0;
}

