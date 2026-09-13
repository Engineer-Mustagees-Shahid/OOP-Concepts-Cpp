#include<iostream>

using namespace std;

class Student{
	
	private:
		
		string name;
		int roll_no;
		string grade;
		
	public:
		
		Student()
		{
			name="Unknown";
			roll_no=0;
			grade="A+";
		}
		
		Student(string n, int r, string g)
		{
			name=n;
			roll_no=r;
			grade=g;
		}
		
		friend istream &operator>>(istream &input, Student &s)
		{
			cout<<"\n Enter your name : ";
			input>>s.name;
			cout<<"\n Enter your Roll no : ";
			input>>s.roll_no;
			cout<<"\n Enter your Grade: ";
			input>>s.grade;
			
			return input;
		}
		
		friend ostream &operator<<(ostream &os, Student &s)
		{
			os<<"\n Name : "<<s.name<<endl;
			os<<"\n Roll No : "<<s.roll_no<<endl;
			os<<"\n Grade: "<<s.grade<<endl;
			
			return os;
		}

};

int main()
{
	Student s1;
	cin>>s1;
	cout<<s1;

	return 0;
}