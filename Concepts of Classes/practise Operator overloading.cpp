#include<iostream>
using namespace std;

class complex{
	
	private:
		
		float real;
		float imaginary;
		
	public:
		
		complex()
		{
			real=0;
			imaginary=0;
		}
		
		complex(float r, float img)
		{
			real=r;
			imaginary=img;
		}
		
		complex operator-(const complex &obj)
		{
			return complex(real-obj.real,imaginary-obj.imaginary);
		}
		
		void display() const
		{
			cout<<real<<" , "<<imaginary<<" i "<<endl;
		}
	
	
};

int main()
{
	complex c1(3.5,4.5);
	c1.display();
	complex c2(3.5,5.5);
	c2.display();
	
	complex sum=c1-c2;
	cout<<endl;
	sum.display();
	
	return 0;
}