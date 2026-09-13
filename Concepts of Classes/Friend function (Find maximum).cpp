#include<iostream>

using namespace std;

class B;

class A{
	
	private:
		
		int data;
		
	public:
		
		A(int data)
		{
			this->data=data;
		}
		
		friend void find_max(const A &a , const B &b);
};

class B{
	
	private:
		
		int data;
		
	public:
		
		B(int data)
		{
			this->data=data;
		}
		
		friend void find_max(const A &a , const B &b);
};

void find_max(const A &a, const B &b)
{
	if(a.data>b.data)
	{
		cout<<"\n Maximum value is "<<a.data<<endl;
	}
	else if(b.data>a.data)
	{
		cout<<"\n Maximum value is "<<b.data<<endl;
	}
}

int main()
{
	A a(20);
	B b(30);
	
	find_max(a,b);
	
	return 0;
}