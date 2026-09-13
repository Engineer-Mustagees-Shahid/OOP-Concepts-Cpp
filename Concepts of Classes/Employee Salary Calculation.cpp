#include<iostream>
#include<string>

using namespace std;

class Person{
	
	protected:
		string name;
		string address;
		
	public:
		Person()
		{
		   name="Unknown";
		   address="Nill";
		}
		
		Person(string name, string address)
		{
			this->name=name;
			this->address=address;
		}
		
		void set_name(string n)
		{
			name=n;
		}
		
		void set_address(string addr)
		{
			address=addr;
		}
		
		string get_name()
		{
			return name;
		}
		
		string get_address()
		{
			return address;
		}
};

class Employee : public Person{
	protected:
		int Employee_no;
		int hours_worked;
	public:
		Employee()
		{
			Employee_no=0;
			hours_worked=0;
		}
		
		Employee(string n, string addr, int emp_no, int hr_work ) : Person(n,addr)
		{
			Employee_no=emp_no;
			hours_worked=hr_work;
		}
		
		void set_Emp_no(int emp_no)
		{
			Employee_no=emp_no;
		}
		
		void set_hours_worked(int hr_work)
		{
			hours_worked=hr_work;
		}
		
		int get_emp_no()
		{
			return Employee_no;
		}
		
		int get_hrs()
		{
			return hours_worked;
		}
	
};

class Production_Worker : public Employee{
	
	protected:
		int shift;
		double hourly_Pay_Rate;
		double salary;
		
	public:
		Production_Worker()
		{
			shift=0;
			hourly_Pay_Rate=0;
			salary=0;
		}
		
		Production_Worker(string name, string address, int emp_no, int hrs_work, int shift, double h_p_r) : Employee(name,address,emp_no,hrs_work) 
		{
			this->shift=shift;
			hourly_Pay_Rate=h_p_r;
		}
		
		void set_s(int s)
		{
			shift=s;
		}
		
		void set_hpr(double hpr)
		{
			hourly_Pay_Rate=hpr;
		}
		
		int get_shift()
		{
			return shift;
		}
		
		double get_hpr()
		{
			return hourly_Pay_Rate;
		}
		
		double calculate_Salary()
		{
			salary=hourly_Pay_Rate*hours_worked;
			
			if(shift==2 && hours_worked>5)
			{
				salary=salary+1000;
			}
			
			return salary;
		}
		
		void print_deatils()
		{
			cout<<" Name of the Employee is : "<<get_name()<<endl;
			cout<<" Address of the Employee is : "<<get_address()<<endl;
			cout<<" Employee ID : "<<get_emp_no()<<endl;
			cout<<" Hours Worked By the Employee : "<<get_hrs()<<endl;
			cout<<" Employee Duty Time ('1' for Day and '2' for Night) : "<<get_shift()<<endl;
			cout<<" Hours Per Rate : "<<get_hpr()<<endl;
			cout<<" Employee Salary is : "<<calculate_Salary()<<endl;
		}
};

int main()
{
	
	Production_Worker emp("M.Mustagees Shahid","IslamAbad",3052,24,2,350);
	emp.calculate_Salary();
	cout<<" Details about the Employee : "<<endl<<endl;
    emp.print_deatils();

	
	return 0;
}