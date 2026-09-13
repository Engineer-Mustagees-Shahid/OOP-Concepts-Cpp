#include<iostream>
using namespace std;

class shape{
	
	public:
		
		virtual void draw()=0;
	
};

class circle: public shape{
	
	public:
		
		void draw()
		{
			cout<<"\n Draw the circle. "<<endl;
		}
};

class rectangle: public shape{
	
	public:
		
		void draw()
		{
			cout<<"\n Draw the Rectangle. "<<endl;
		}
};

int main()
{
	shape *shape1= new circle;
	shape *shape2= new rectangle;
	
	shape1->draw();
	shape2->draw();
	
	delete shape1;
	delete shape2;
	
	return 0;
}