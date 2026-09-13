#include<iostream>
#include<string>
using namespace std;

struct Doctor{
 
    string name;
	string specilization;
		
};

struct Hospital{
	
	string name;
	Doctor *dctr;
	
	Hospital(){
		
		dctr=new Doctor[3];
	}

	
	~Hospital(){
		
		delete [] dctr;
		dctr=NULL;
	}
};

void input_details(struct Hospital *hospitals, int n)
{
	
	for(int i=0; i<n; i++)
	{
		cout<<endl<<" Enter the name of the "<<i+1<<" Hospital : ";
		getline(cin,hospitals[i].name);
		
		cout<<"\n\n";
		
		for(int j=0; j<3; j++)
		{
			cout<<" Enter the name of "<<j+1<<" Doctor is : ";
			getline(cin,hospitals[i].dctr[j].name);
			cout<<endl<<" Enter the Specialization of the "<<hospitals[i].dctr[j].name<<" is : ";
			getline(cin,hospitals[i].dctr[j].specilization);
			cout<<"------------------------------------------"<<endl;
		}
		cout<<endl;
	}
	
}

void display_data(struct Hospital *hospitals, int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<" Name of the "<<i+1<<" Hospital is : "<<hospitals[i].name<<endl<<endl;
		for(int j=0; j<3; j++)
		{
			cout<<"-----------------------------------*_*----------------------"<<endl;
			cout<<" Name of the "<<j+1<<" Doctor is : "<<hospitals[i].dctr[j].name<<endl;
			cout<<" Specialization of "<<hospitals[i].dctr[j].name<<" is : "<<hospitals[i].dctr[j].specilization<<endl;
		}
		
	}
	
}

int main()
{
	int n;
	cout<<" Enter the number of Hospitals : ";
	cin>>n;
	cin.ignore();
	Hospital *hospitals= new Hospital [n];
	input_details(hospitals,n);
	display_data(hospitals,n);
	
	delete [] hospitals;
	hospitals=NULL;
	
	return 0;
}