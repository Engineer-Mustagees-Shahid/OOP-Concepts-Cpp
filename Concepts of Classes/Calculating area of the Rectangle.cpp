#include<iostream>
using namespace std;

class Width;

class Length{
	
	private:
		
		double value;
		
	public:
		
		Length(double v)
		{
			value=v;
		}

    friend double calculate_area(const Length &l, const Width &w);
};

class Width{
	
	private:
		
		double value;
		
	public:
		
		Width(double v)
		{
			value=v;
		}

    friend double calculate_area(const Length &l, const Width &w);
};

double calculate_area(const Length &l, const Widt &w)
{
    return (l.value * w.value);
}

int main()
{
	
    Length l(10.5);
    Width w(4.2);

    double area=calculate_area(l,w);
    cout<<" The area is: "<<area<<endl;

    return 0;
}
