#include<iostream>
#include<string>

using namespace std;

class data_member{
	
	private:
		
		float value;
		
	public:
		
		data_member()
		{
			value=0;
		}
		
		
		data_member(int v)
		{
			value=v;
		}
		
		data_member operator +(const data_member &member)
		{
			
			data_member temp;
			temp.value=this->value+member.value;
			
			return temp;
		}
		
		void display()
		{
			cout<<"\n Sum of value : "<<value<<endl;
		}
	
};

int main()
{
	float x,y;
	
	cout<<"\n Enter the first Number : ";
	cin>>x;
	cout<<"\n Enter the Second Number : ";
	cin>>y;
	
	data_member num_1(x);
	data_member num_2(y);
	data_member sum;
	
	sum=num_1+num_2;
	
	sum.display();
	
	return 0;
}
