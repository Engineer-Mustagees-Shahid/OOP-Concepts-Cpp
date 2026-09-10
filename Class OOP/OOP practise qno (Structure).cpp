#include<iostream>
#include<string>
using namespace std;



struct Engine{
	
	string horsepower;
	float efficency;
	
};

struct Car{
	
	string model;
	Engine *engine;
	
};

void initialize_car(Car *car)
{
	
	car->engine = new Engine;
	cout<<" Enter the model of the car : ";
	cin>> car->model;
	cout<<" Enter the horsepower of of engine : ";
	cin>>car->engine->horsepower;
	cout<<" Enter the efficency of car engine : ";
	cin>>car->engine->efficency;
	
}

void display_specification(Car *car)
{
	cout<<"-------------------Details---------------------- ";
	cout<<" The model of the Toyotta Car is : "<<car->model<<endl;
	cout<<" The horsepower of the engine is : "<<car->engine->horsepower<<endl;
	cout<<" The efficency of the Engine is : "<<car->engine->efficency<<endl;
	
}

void deallocation_memoery(Car *car)
{
	delete car->engine;
	car->engine=NULL;
}



int main()
{
	Car car;
	initialize_car(&car);
	display_specification(&car);
	
	return 0;
}