#include<iostream>

using namespace std;

class Cylinder;

class Box{
	
	private:
		
		float volume;
	
	public:
		
		Box(float vol)
		{
			volume=vol;
		}
		
		friend float total_volume(const Box b, const Cylinder c);
};

class Cylinder{
	
	private:
		
		float volume;
		
	public:
		
		Cylinder(float vol)
		{
			volume=vol;
		}
		
		friend float total_volume(const Box b, const Cylinder c);
};

float total_volume(const Box b, const Cylinder c)
{
	float result;
	result=b.volume+c.volume;
	return result;
}

int main()
{
	Box b(23.5);
	Cylinder c(20);
	float result=total_volume(b,c);
	cout<<"\n Total Volume is : "<<result<<endl;
	
	return 0;
}