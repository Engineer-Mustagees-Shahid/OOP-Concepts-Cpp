#include<iostream>
using namespace std;

struct Rectangle{
	
	float length;
	float width;
};

int calculate_area(struct Rectangle r )
	{
		return r.length*r.width;
	}

int main()
{
	Rectangle rec;
	cout<<" Enter the length of the Rectangle : ";
	cin>>rec.length;
	cout<<" Enter the width of the Rectangle : ";
	cin>>rec.width;
	double area=calculate_area(rec);
	cout<<" The area of the Rectangle is : "<<area<<endl;

	return 0;
}