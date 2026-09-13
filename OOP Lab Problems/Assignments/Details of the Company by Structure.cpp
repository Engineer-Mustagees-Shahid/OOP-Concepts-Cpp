#include<iostream>
using namespace std;

struct Address{
	
	string city;
	string zip;
};

struct Company{
	
	string name;
	double revenue;
	Address addr;
};

void set_data(struct Company *comp,int n)
{
	cout<<endl<<"-------------------------Details of the Company--------------- :"<<endl<<endl;
	cin.ignore();
	for(int i=0; i<n; i++)
	{
		cout<<" Enter the Name of the Company : ";
		getline(cin,comp[i].name);
		cout<<" Enter the City of in which Company is Established : ";
		getline(cin,comp[i].addr.city);
		cout<<" Enter the zip code of the city : ";
		getline(cin,comp[i].addr.zip);
		cout<<" Enter the Revenue of the Comapny : $ ";
		cin>>comp[i].revenue;
		cin.ignore();	
		cout<<"-------------------------------------"<<endl;
	}
	cout<<endl<<endl;
}

void display_data(struct Company *comp, int n)
{
	cout<<endl<<"-------------------------Details of the Company--------------- :"<<endl<<endl;
	for(int i=0; i<n; i++)
	{
		cout<<" Name of "<<i+1<<" company is : "<<comp[i].name<<endl;
		cout<<" City of "<<i+1<<" company is : "<<comp[i].addr.city<<endl;
		cout<<" Zip code of "<<i+1<<" company is : "<<comp[i].addr.zip<<endl;
		cout<<" Revenue of "<<i+1<<" company is : $ "<<comp[i].revenue<<endl;
		cout<<"-----------------------------------------"<<endl<<endl;
	}
	
}


int main()
{
	int n;
	cout<<" Enter the number of Companies : ";
    cin>>n;
	Company *comp;
	comp=new Company[n];
	set_data(comp,n);
	display_data(comp,n);
	
	delete [] comp;
	comp=NULL;
	
	return 0;
}