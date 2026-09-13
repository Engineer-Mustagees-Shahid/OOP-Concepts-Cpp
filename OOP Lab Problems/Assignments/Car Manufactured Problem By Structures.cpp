#include<iostream>
using namespace std;

struct Car{
	
    string brand;
    int year;
    float price;
};

void update_price(Car *c, float discount) 
{
    c->price= c->price-(c->price*(discount/100));
}

int main() 
{
    Car car;
    float discount;
    
    cout<<"Enter the car brand : ";
    getline(cin,car.brand);
    cout<<"Enter the manufacturing year : ";
    cin>>car.year;  
    cout<<"Enter the car price : $ ";
    cin>>car.price;
    
    cout<<endl<<"Enter the discount percentage of car : ";
    cin>>discount;
    update_price(&car,discount);
    cout<<endl<<endl<<"Updated car details is : "<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Brand of the car is : " <<car.brand<<endl;
    cout<<"Manufacturing year of the car is : "<<car.year<<endl;
    cout<<"Discounted Price of car is : $ " <<car.price<<endl;

    return 0;
}
