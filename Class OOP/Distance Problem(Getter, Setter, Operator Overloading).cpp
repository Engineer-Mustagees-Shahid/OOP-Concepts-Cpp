#include<iostream>

using namespace std;

class Distance
{
	private:
		
		int feet;
		int inches;
		static int instance_count;
		
		void normalize() // normalize the function
		{
			if(inches>=12)
			{
				feet+=inches/12;
				inches%=12;
			}
		}
		
		public:
			
			Distance() //default constructor
			{
				feet=0;
				inches=0;
				instance_count++;
			}
			
			Distance(int f, int i) // Parametrized constructor
			{
				feet=f;
				inches=i;
				normalize();
				instance_count++;
			}
				
			Distance(const Distance &d)
			{
				feet=d.feet;
				inches=d.inches;
				instance_count++;
			}
			
			~Distance() //Destructor
			{
				instance_count--;
			}
			
			int get_feet() const // Getter function
			{
				return feet;
			}
			
			int get_inches() const //Getter Function
			{
				return inches;
			}
			
			void set_feet(int f) // Setter Function
			{
				feet=f;
			}
			
			void set_inches(int i) // Setter Function
			{
				inches=i;
				normalize();
			}
			
			static int get_instance_count() // Gettr function for instance count
			{
				return instance_count;
			}
			
			Distance operator+(const Distance &d) const // Operator overloading of +
			{
				return Distance(feet+d.feet, inches+d.inches);
			}
			
			bool operator<(const Distance &d) const
			{
				if(feet<d.feet)
				{
					return true;
				}
				
				if(feet==d.feet && inches<d.inches)
				{
					return true;
				}
				
				return false;
			}
			
			Distance &operator+=(const Distance &d) // Operator overloading of +=
			{
				feet+=d.feet;
				inches+=d.inches;
				normalize();
				return *this;
			}
			
			Distance &operator++() // Operator overloading of ++
			{
				++inches;
				normalize();
				return *this;
			}
			
			Distance operator++(int)
			{
				Distance temp=*this;
				++(*this);
				return temp;
			}
			
			Distance &operator--() // Operator overloading of --
			{
				if(inches>0)
				{
					--inches;
				}
				else if(feet>0)
				{
					--feet;
					inches=11;
				}
				
				return *this;
			}
			
			Distance operator--(int)
			{
				Distance temp=*this;
				--(*this);
				return temp;
			}
			
			friend ostream &operator<<(ostream &out, const Distance &d) // Operator overloading of <<
			{
				out<<d.feet<<" feet "<<d.inches<<" inches "<<endl;
				return out;
			}
			
			friend istream &operator>>(istream &in , Distance &d) // Operator overloading of >>
			{
				cout<<" Enter feet : ";
				in>>d.feet;
				cout<<" Enter inches: ";
				in>>d.inches;
				d.normalize();
				return in;
			}

};

int Distance::instance_count=0;

int main()
{
	Distance d1,d2(15,8),d3(d2);
	
	cout<<" Instance Count: "<<Distance::get_instance_count()<<endl;
    cout<<" Distance d1: "<<d1<<endl;
    cout<<" Distance d2: "<<d2<<endl;
    cout<<" Distance d3: "<<d3<<endl;
    
    cout<<"\n Enter new Distance for d1: "<<endl;
    cin>>d1;
    cout<<" Updated d1: "<<d1<<endl;
    
    Distance d4=d1+d2;
    cout<<" d1+d2 = "<<d4<<endl;
    
    d1+=d3;
    cout<<" d1+=d3: "<<d1<<endl;
    
    ++d1;
    cout<<" After ++d1: "<<d1<<endl;
    
    --d1;
    cout<<" After d1--: "<<d1<<endl;
    
    cout<<"\n Final Instance Count: "<<Distance::get_instance_count()<<endl;
    
    return 0;
}
