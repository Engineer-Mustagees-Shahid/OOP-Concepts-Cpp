#include<iostream>
using namespace std;

class Coffe_Order{
	
	private:
		
		int total_cost;
		
	public:
		
		void process_order(int size, int price)
		{
			total_cost=size*price;
			cout<<"\n Total Price is : "<<total_cost<<" $ "<<endl;
		}
	
};

class Custom_Order : public Coffe_Order{
	
	public:
			
		void process_order(int size, int price)
		{
			cout<<"\n Welcome to our Coffe Shop *_* "<<endl;
			Coffe_Order::process_order(size,price);
			
		}
	
};

int main()
{
	int size,price;
	cout<<"\n Enter the size in (ounces) : ";
	cin>>size;
	cout<<"\n Enter the price in (Dollars $ ): ";
	cin>>price;
	
	Custom_Order costom;
	cout<<"\n Costum Order : "<<endl;
	costom.process_order(size,price);
	
	Coffe_Order  std;
	cout<<"\n Standard Order : "<<endl;
	std.process_order(size,price);
	
	
	return 0;
}