#include<iostream>
using namespace std;

class Force;

class Particle{
	
	private:
		
		double velocity;
		double acceleration;
		
	public:
		
		Particle(double v, double a)
		{
			velocity=v;
			acceleration=a;
		}
		
		void display_state()
		{
			cout<<" Velocity  is "<<velocity<<" m/s "<<endl;
			cout<<" Acceleration is "<<acceleration<<" m/s^2 "<<endl;
		}

    friend class Force;
};

class Force{
	
	public:
		
		void apply_force(Particle &p, double force_value, double mass)
		{
			p.acceleration=force_value/mass;
			p.velocity=p.velocity+p.acceleration;
			cout<<" Force Applied and Particle motion update "<<endl;
		}
		
};

int main()
{
	
    Particle p1(0,0);
    cout<<" Initial State is "<<endl;
    p1.display_state();

    Force f;
    f.apply_force(p1,10,2);

    cout<<" After Applying Force: "<<endl;
    p1.display_state();

    return 0;
}
