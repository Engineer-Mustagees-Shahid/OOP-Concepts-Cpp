#include<iostream>

using namespace std;

class Coach{
	
	public:
		
		string name;
		
		Coach()
		{
			name="M.ALi";
			cout<<"\n Couch "<<name<<" is created. "<<endl;
		}
		
		void display()
		{
			cout<<"\n Coach name is : "<<name<<endl;
		}
		
		~Coach()
		{
			cout<<"\n Couch is destroyed."<<endl;
		}
	
};

class Team{
	
	private:
		
		string name;
	
	public:
		
		Team()
		{
			name="Multan Sultan.";
			cout<<"\n Team "<<name<<"is created."<<endl;
		}
		
		void display( Coach &c1)
		{
			cout<<"\n Team coach is "<<c1.name<<endl;
		}
		
		~Team()
		{
			cout<<"\n Team is Destroyed."<<endl;
		}
};

int main()
{
	Coach *c1 = new Coach;
	c1->display();
{
		
	Team t;
	t.display(*c1);
}		
	c1->display();
	delete c1;
	
  return 0;
}