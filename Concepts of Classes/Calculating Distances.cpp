#include<iostream>
#include<cmath>

using namespace std;

class Point_B;

class Point_A{
	
	private:
		
		double x,y;
		
	public:
		
		Point_A(double x, double y)
		{
			this->x=x;
			this->y=y;
		}

    friend double calculate_distance(const Point_A &p1, const Point_B &p2);
};

class Point_B{
	
	private:
		
		double x,y;
		
	public:
		
		Point_B(double x, double y)
		{
			this->x=x;
			this->y=y;
		}

    friend double calculate_distance(const Point_A &p1, const Point_B &p2);
};

double calculate_distance(const Point_A &p1, const Point_B &p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main()
{
	
    Point_A p1(1,2);
    Point_B p2(4,6);

    double distance=calculate_distance(p1,p2);
    cout<<" The Euclidean distance between the points are : "<<distance<<endl;

    return 0;
}
