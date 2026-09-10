#include<iostream>
#include<fstream>

void create_file();
void write_in_file();
void app_age();
char file_name[20];

using namespace std;

int main()
{
	create_file();
	write_in_file();
	app_age();
	
	
	return 0;
}

void create_file()
{
    cout<<" Enter the file name : ";
    cin>>file_name;
	ofstream student_data_file(file_name);
	if (student_data_file.is_open())
	{
		cout<<endl<<" The file is created successfully!"<<endl<<endl;
	}
	
	else 
	{
		cerr<<endl<<" The file is not created !"<<endl;
	}
	student_data_file.close();
}

void write_in_file()
{
	string name;
	string roll_no;
	string hobbies[3];
	ofstream write(file_name,std::ios::out);
	if(write.is_open())
	{
		cout<<" Enter your name : ";
		cin>>name;
		cout<<endl<<" Enter your Roll no : ";
		cin>>roll_no;
		cout<<endl<<" Enter your three hobbies : ";
		for (int i=0 ; i<3; i++)
		{
			cin>>hobbies[i];
		}
		write<<" Name : "<<name<<endl;
		write<<endl<<" Roll No : "<<roll_no<<endl;
		write<<endl<<" Hobbies : ";
		for (int i=0; i<3 ; i++)
		{
		write<<hobbies[i]<<"\t";
		}
		write.close();
		cout<<endl<<" Data is written Successfully !";
	}
	else 
	{
		cerr<<endl<<" Data is not written Successfully !";
	}
	
}

void app_age()
{
	int age[1];
	cout<<endl<<endl<<" Enter your age : ";
	cin>>age[0];
	ofstream add_age(file_name,std::ios::app);
	if(add_age.is_open())
	{
		add_age<<endl<<endl<<" Age : "<<age[0];
		
		add_age.close();
	    cout<<endl<<" Age is written succeessfully !";
	}
	
	else 
	{
		cerr<<endl<<" Age is not written suceesfully ! ";
	}
	
}