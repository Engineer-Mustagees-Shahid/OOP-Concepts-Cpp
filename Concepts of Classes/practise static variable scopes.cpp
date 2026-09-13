#include <iostream>
using namespace std;

class count_dest{
	
	private:
		
		int data;
		
	public:
		
		count_dest(int val)
		{
			data=val;
			cout<<"\n Object "<<data<<" Constructor.";
		}
		
		~count_dest()
		{
			cout<<"\n Object "<<data<<" Destructor.";
		}

};

count_dest one(1);

void create()
{
	count_dest fifth(5);
	cout<<"\t Local automatic in create. "<<endl;
	
	static count_dest sixth(6);
	cout<<"\t Local Static in create."<<endl;
	
	count_dest seven(7);
	cout<<"\t Local automatic in create."<<endl;
}

int main()
{
	cout<<"\t Global object before main."<<endl;
	count_dest two(2);
	cout<<"\t Local automatic in main."<<endl;
	static count_dest third(3);
	cout<<"\t Local static in main."<<endl;
	create();
	count_dest forth(4);
	cout<<"\t Local automatic in main."<<endl;
	cout<<"\n Thanks."<<endl;
	return 0;
}