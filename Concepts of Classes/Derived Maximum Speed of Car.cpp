#include<iostream>
using namespace std;

class Car{
	
	private:
		
		int current_speed;
		static int max_speed;
	
	public:
		
		Car()
		{
			current_speed=0;
		}
		
		void set_speed(int speed)
	{
			current_speed=speed;
			
			if(speed>max_speed)
		{
				max_speed=speed;
		}
	}
			
		int get_current_speed()
		{
			return current_speed;
		}
		
		static int get_max_speed()
		{
			return max_speed;
		}
	
};

int Car::max_speed=0;

int main()
{
	Car car1,car2,car3;

    car1.set_speed(230);
	cout<<endl<<" Current speed of 1st car is : "<<car1.get_current_speed()<<endl;
	cout<<endl<<" Maximum speed of 1st car is : "<<car1.get_max_speed()<<endl;

    car2.set_speed(225);
	cout<<endl<<" Current speed of 2nd car is : "<<car2.get_current_speed()<<endl;
	cout<<endl<<" Maximum speed of 2nd car is : "<<car2.get_max_speed()<<endl;

    car3.set_speed(240);
	cout<<endl<<" Current speed of 3rd car is : "<<car3.get_current_speed()<<endl;
	cout<<endl<<" Maximum speed of 3rd car is : "<<car3.get_max_speed()<<endl;
	
	return 0;
}