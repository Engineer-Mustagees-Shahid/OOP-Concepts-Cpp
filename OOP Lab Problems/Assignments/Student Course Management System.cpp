#include<iostream>
#include<string>
#include<limits>
using namespace std;

struct Professor{
	
    string name;
    string subject;
};

struct Student {
	
    string name;
    int age;
    string id;
    float grade;
};

struct Course{
	
    string name;
    string code;
    Professor instructor;
    int student_count;
    int max_students;
    Student *students; 
};

struct University{
	
    string name;
    int course_count;
    Course *courses; 
};


void add_course(University *uni) 
{
    cout<<endl<<" Adding a new course... "<<endl;
    
    Course *temp = new Course[uni->course_count + 1];
    
    for(int i=0; i<uni->course_count; i++) 
	{
        temp[i] = uni->courses[i]; 
    }
    if(uni->courses!=NULL)
    {
    	delete[] uni->courses;
	}
 
    uni->courses=temp; 
    
    int index=uni->course_count;
    uni->course_count++;

    cout<<endl<<" Enter course name: ";
    cin.ignore();
    getline(cin,uni->courses[index].name);
    cout<<endl<<" Enter course code: ";
    getline(cin,uni->courses[index].code);

    cout<<" Enter professor name: ";
    getline(cin,uni->courses[index].instructor.name);
    cout<<" Enter professor subject: ";
    getline(cin,uni->courses[index].instructor.subject);

    cout<<" Enter max students for this course: ";
    cin>>uni->courses[index].max_students;
    
    uni->courses[index].student_count=0;
    uni->courses[index].students= new Student[uni->courses[index].max_students]; // Allocate students dynamically

    cout<<" Course added successfully! "<<endl;
}

void enroll_student(University *uni) 
{
    if (uni->course_count==0) 
	{
        cout<<endl<<" No courses available Add a course first! "<<endl;
        return;
    }

    cout<<endl<<" Available courses: "<<endl;
    for(int i=0; i<uni->course_count; i++) 
	{
        cout<<i+1<<". "<<uni->courses[i].name<<" ("<<uni->courses[i].code<<")"<<endl;
    }
    
    int choice;
    cout<<" Select course number: ";
    cin>>choice;
    choice--;

    if(choice <0 || choice >= uni->course_count) 
	{
        cout<<endl<<" Invalid choice! "<<endl;
        return;
    }

    if (uni->courses[choice].student_count >= uni->courses[choice].max_students) 
	{
        cout<<" Course offereing is full! Cannot enroll more students. "<<endl;
        return;
    }

    int index=uni->courses[choice].student_count;
    uni->courses[choice].student_count++;

    cout<<" Enter the student name: ";
    cin.ignore();
    getline(cin,uni->courses[choice].students[index].name);
    cout<<" Enter the student ID: ";
    getline(cin,uni->courses[choice].students[index].id);
    cout<<" Enter the student age: ";
    cin>>uni->courses[choice].students[index].age;
    cout<<" Enter the student grade: ";
    cin>>uni->courses[choice].students[index].grade;

    cout<<" Student enrolled successfully in "<<uni->courses[choice].name<<endl;
}

void display_courses(const University *uni) 
{
    if(uni->course_count==0) 
	{
        cout<<endl<<" No courses available! "<<endl;
        return;
    }

    cout<<endl<<" Courses offered by "<<uni->name<<":"<<endl;
    
    for (int i=0; i<uni->course_count; i++) 
	{
        cout<<endl<<" Course "<<i+1<< ": "<<uni->courses[i].name<<" ("<<uni->courses[i].code << ")"<<endl;
        cout<<" Instructor: "<<uni->courses[i].instructor.name<<" - "<<uni->courses[i].instructor.subject<<endl;
        cout<<" Enrolled Students: "<<uni->courses[i].student_count<<"/"<<uni->courses[i].max_students<<endl;
        
        for (int j=0; j<uni->courses[i].student_count; j++) 
		{
        cout<<"\tStudent "<<j+1<<": "<<uni->courses[i].students[j].name<<"(ID: "<<uni->courses[i].students[j].id<<", Age: "<<uni->courses[i].students[j].age 
        <<", Grade: "<<uni->courses[i].students[j].grade<<")"<<endl;
        }
    }
}


void update_grade(University *uni) 
{
    cout<<endl<<" Enter student ID to update grade: ";
    string id;
    cin>>id;

    for(int i=0; i<uni->course_count; i++) 
	{
        for(int j=0; j<uni->courses[i].student_count; j++) 
		{
            if(uni->courses[i].students[j].id == id) 
			{
                cout<<" Current grade: "<<uni->courses[i].students[j].grade<<endl;
                cout<<" Enter new grade: ";
                cin>>uni->courses[i].students[j].grade;
                cout<<" Grade updated successfully! "<<endl;
                return;
            }
        }
    }

    cout<<" Student not found! "<<endl;
}


void remove_student(University *uni) 
{
    cout<<endl<<" Enter student ID to remove: ";
    string id;
    cin>>id;

    for(int i=0; i<uni->course_count; i++) 
	{
        for(int j=0; j<uni->courses[i].student_count; j++) 
		{
            if (uni->courses[i].students[j].id == id) 
			{
                cout<<"Removing "<<uni->courses[i].students[j].name<<" from "<<uni->courses[i].name<<endl;

                for (int k=j; k<uni->courses[i].student_count; k++) 
				{
                    uni->courses[i].students[k]= uni->courses[i].students[k+1];
                }

                uni->courses[i].student_count--;
                
                cout<<endl<<" Student removed successfully! "<<endl;
                return;
            }
        }
    }

    cout<<" Student not found! "<<endl;
}

void clean_up(University *uni) 
{
	if(uni->courses!=NULL)
{
	for(int i=0; i<uni->course_count; i++) 
	 {
        delete[] uni->courses[i].students;
     }
        delete[] uni->courses;
        uni->courses=NULL;
}

}

int main() 
{
    University uni;
    
    cout<<" Enter university name: ";
    getline(cin,uni.name);
    uni.course_count = 0;
    uni.courses=NULL;

    int choice;
    
    do {
        cout<<endl<<"-----------------------------------------Course Management System-----------------------------------------"<<endl;
        cout<<" 1. Add Course "<<endl;
        cout<<" 2. Enroll Student "<<endl;
        cout<<" 3. Display Courses & Students "<<endl;
        cout<<" 4. Update Student Grade "<<endl;
        cout<<" 5. Remove Student from Course "<<endl;
        cout<<" 6. For Exiting "<<endl;
        cout<<endl<<" Enter choice: ";
        cin>>choice;

        switch(choice) 
		{
            case 1:
			    add_course(&uni); 
			break;
            case 2:
			    enroll_student(&uni);
			break;
            case 3:
			    display_courses(&uni); 
			break;
            case 4:
			    update_grade(&uni); 
			break;
            case 5:
			    remove_student(&uni); 
			break;
            case 6:
			    cout<<" Exiting !"<<endl;
			break;
            default:
			    cout<<" Invalid choice!"<<endl;
        }
    }while(choice!=6);

    clean_up(&uni);
    
    return 0;
}
