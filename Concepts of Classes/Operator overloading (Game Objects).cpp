#include<iostream>

using namespace std;

class Gameobject{
	
	private:
		
		int x;
		int y;
		
	public:
		
		Gameobject()
		{
			x=0;
			y=0;
		}
		
		Gameobject(int x, int y)
		{
			this->x=x;
			this->y=y;
		}
		
		Gameobject operator+(const Gameobject &obj) 
		{
			Gameobject temp;
			temp.x=this->x+obj.x;
			temp.y=this->y+obj.y;
			
			return temp;
		}
		
		Gameobject operator-(const Gameobject &obj)
		{
			Gameobject temp;
			temp.x=this->x-obj.x;
			temp.y=this->y-obj.y;
			
			return temp;
		}
		
		bool operator==(const Gameobject &obj)
		{
			if(this->x==obj.x && this->y==obj.y)
			return true;
			
			return false;
		}
		
		friend ostream &operator<<(ostream &os, const Gameobject &obj)
		{
			os<<"\n Current location is ( "<<obj.x<<" , "<<obj.y<<" )"<<endl;
			
			return os;
		}
	
};

int main()
{
	
	Gameobject a1(5,6);
	Gameobject a2(6,5);
	
	a1=a1+a2;
	
	cout<<a1<<endl;
	
	a1=a1-a2;
	
	cout<<a1<<endl;
	
	if(a1==a2)
	{
		cout<<"\n Both objects are in same position. "<<endl;
	}
	
	else
	{
		cout<<"\n Both objects are not in same position. "<<endl;
	}
	
	
	return 0;
}