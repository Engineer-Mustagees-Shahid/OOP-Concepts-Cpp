#include<iostream>

using namespace std;

class Time{
	
	protected:
		
		int hours;
		int minutes;
		int seconds;
		
		void normalize_time()
		{
			hours+=minutes/60;
			minutes%=60;
			
			minutes+=seconds/60;
			seconds%=60;
		}
		
		
	public:
		
		Time()
		{
			hours=0;
			minutes=0;
			seconds=0;
		}
		
		Time(int h, int m, int s)
		{
			hours=h;
			minutes=m;
			seconds=s;
		}
		
		Time operator+(const Time &time) 
		{
			Time temp;
			temp.hours=hours+time.hours;
			temp.minutes=minutes+time.minutes;
			temp.seconds=seconds+time.seconds;
			temp.normalize_time();
			
			return temp;
		}
		
		Time &operator=(const Time &time) 
		{
			if(this!=&time)
			{
				hours=time.hours;
				minutes=time.minutes;
				seconds=time.seconds;
			}
			
			return *this;
		}
		
		bool operator<(const Time &time) const
		{
			if(hours<time.hours)
			return true;
			if(hours==time.hours && minutes<time.minutes)
			return true;
			if(hours==time.hours && minutes==time.minutes && seconds<time.seconds)
			return true;
			
			return false;
		}
		
		friend ostream &operator<<(ostream &os, const Time &time )
		{
			os <<"\n Time : "<<time.hours<<" : "<<time.minutes<<" : "<<time.seconds<<endl;
			
			return os;
		}
		
		~Time()
		{
			cout<<"Time object is destroyed ("<<hours<<" : "<<minutes<<" : "<<seconds<<" )"<<endl;
		}
		
};

int main()
{
	Time t1(4,59,59);
	Time t2(4,01,01);
	
	Time t3=t2+t1;
	cout<<"\n Sum of Time 1 and Time 2 is : "<<t3<<endl;
	
	Time t4=t2;
	
	cout<<"\n Time 2 assign to the Time 4 "<<t4<<endl;
	
	if(t1<t2)
	{
		cout<<"\n Time 1 is goes more then the first one.\n "<<endl;
	}
	else
	{
		cout<<"\n Time 2 is goes more then the second one.\n "<<endl;
	}
	
	return 0;
}