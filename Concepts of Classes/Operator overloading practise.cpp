#include<iostream>

using namespace std;

class Prefix_Increemnent{
	
	private:
		
		int num;
		
	public:
		
		Prefix_Increemnent()
		{
			num=0;
		}
		
		Prefix_Increemnent(int num)
		{
			this->num=num;
		}
		
		Prefix_Increemnent &operator++()
		{
			++num;
			return *this;
		}
		
		void display() const
		{
			cout<<"\n Value is : "<<num<<endl;
		}

};

class Postfix_Increement{
	
	private:
		
		int num;
		
	public:
		
		Postfix_Increement()
		{
			num=0;
		}
		
		Postfix_Increement(int num)
		{
			this->num=num;
		}
		
		Postfix_Increement operator++(int)
		{
		
			Postfix_Increement temp;
			temp=*this;
			
			num++;
			
			return temp;
		}

		void display() const
		{
			cout<<"\n Value is : "<<num<<endl;
		}
			
};

class Prefix_Decreement{
	
	private:
		
		int num;
		
	public:
		
		Prefix_Decreement()
		{
			num=0;
		}
		
		Prefix_Decreement(int num)
		{
			this->num=num;
		}
		
		Prefix_Decreement &operator--()
		{
			--num;
			return *this;
		}
		
		void display() const
		{
			cout<<"\n Value is : "<<num<<endl;
		}
};

class Postfix_Decreement{
	
	private:
		
		int num;
		
	public:
		
		Postfix_Decreement()
		{
			num=0;
		}
		
		Postfix_Decreement(int num)
		{
			this->num=num;
		}
		
		Postfix_Decreement operator--(int)
		{
			Postfix_Decreement temp;
			temp=*this;
			
			num--;
			
			return temp;
		}
		
		void display() const
		{
			cout<<"\n Value is : "<<num<<endl;
		}
};

int main()
{
	Postfix_Increement num(5);
	num++;
	num.display();
	
	Postfix_Decreement num1(5);
	num1--;
	num1.display();
	
	Prefix_Increemnent num2(5);
	++num2;
	num2.display();
	
	Prefix_Decreement num3(5);
	--num3;
	num3.display();
	
	return 0;
}