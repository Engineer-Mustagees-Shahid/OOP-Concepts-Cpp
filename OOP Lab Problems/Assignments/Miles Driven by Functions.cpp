#include<iostream>
using namespace std;

double total_cost(double,double);

int main()
{
   double no_of_days,no_of_miles,result;
	
   cout<<"Enter the number of days :";
   cin>>no_of_days;
   cout<<endl<<"Enter the no of miles driven :";
   cin>>no_of_miles;
   if( (no_of_days <=0 || no_of_miles <=0) )
   {
   	cout<<endl<<"Invalid days and miles.";
   	return 01;
   }
   result=total_cost(no_of_days,no_of_miles);
   cout<<endl<<"Total cost is : "<<result<<" $ ";
	
	return 0;	
}

double total_cost(double days,double miles)
{
	double result;
	
	if (days>30)
	{
		result= (days*25)+(miles*0.15);
		result=result-(result*0.2);
	}
	else if (days<15)
	{
		result= (days*(25+1.99))+(miles*0.15);
	}
	else
	 
	 result= (days*25)+(miles*0.15);
	
	
	return result;
}