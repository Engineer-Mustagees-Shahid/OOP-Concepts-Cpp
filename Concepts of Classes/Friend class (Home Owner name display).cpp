#include<iostream>

using namespace std;

class Room;

class Home{
	
	private:
		
		string owner_name;
		
	public:
		
		Home(string owner)
		{
			owner_name=owner;
		}
		
		friend class Room;
};

class Room{
	
	public:
		
		void display(const Home &h)
		{
			cout<<"\n Owner name is : "<<h.owner_name<<endl;
		}
};

int main()
{
	Home h("ALi");
	Room r;
	r.display(h);
	
	return 0;
}