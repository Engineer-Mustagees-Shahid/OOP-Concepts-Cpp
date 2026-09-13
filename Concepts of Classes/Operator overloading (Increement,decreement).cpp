#include<iostream>

using namespace std;

class Counter{
	
	private:
		
		int data;
		
	public:
		
		Counter()
		{
			data=0;
		}
		
		Counter(int data)
		{
			this->data=data;
		}
		
		// Prefix Increement
		
		Counter &operator++()
		{
			++data;
			return *this;
		}
		
		// Postfix Increement
		
		Counter &operator++(int)
		{
			Counter temp=*this;
			++data;
			
			return *this;
		}
		
		// prefix decreement
		
		Counter &operator--()
		{
			--data;
			return *this;
		}
		
		// postfix decreement
		
		Counter &operator--(int)
		{
			Counter temp;
			temp=*this;
			
			--data;
			return *this;
		}
		
		friend ostream &operator<<(ostream &os, const Counter &obj)
		{
			os<<"\n The value of variable is "<<obj.data<<endl;
			
			return os;
		}

};


int main()
{
	Counter data(5);
	data--;
	cout<<data<<endl;
	Counter d1=--data;
	cout<<d1<<endl;
	data++;
	cout<<data<<endl;
	++data;
	cout<<data<<endl;

	return 0;
}