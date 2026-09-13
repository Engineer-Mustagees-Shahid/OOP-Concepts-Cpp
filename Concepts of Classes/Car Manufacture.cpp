#include<iostream>
using namespace std;

class Engine{
	
	public:
		
		Engine()
		{
			cout<<" Engine Constructed "<<endl;
		}
		
		~Engine()
		{
			cout<<" Engine is Destructed "<<endl;
		}
		
		void start()
		{
			cout<<" Engine is Starting Now ! "<<endl;
		}
		
};

class Car{
	
	private:
		
		Engine engn;
		
	public:
		
		Car()
		{
			cout<<" Car is Constructed "<<endl;
			engn.start();
		}
		
		~Car()
		{
			cout<<" Car is Destructed "<<endl;
		}
		
};

int main()
{
	Car car;
	
	return 0;
}

