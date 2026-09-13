#include<iostream>
#include<string>

using namespace std;

class Employee{
	
	public:
		
		string name;

        Employee(string n)
        {
        	name=n;
			cout<<" Employee "<<name<<" is created  "<<endl;
		}
		
		~Employee()
		{
			cout<<" Employee "<<name<<" is destroyed."<<endl;
		}
		
		void display()	
		{
			cout<<" -->> "<<name<<endl;
		}
    
};


class Department{
	
	public:
		
		string dept_name;
        Employee *emp1;
        Employee *emp2;
		
		Department(string name)
		{
			dept_name=name;
			emp1=NULL;
			emp2=NULL;
			
			cout<<" Department "<<dept_name<<" is Created "<<endl;
		}
		
		~Department()
		{
			cout<<" Department "<<dept_name<<" is Destroyed "<<endl;
		}
		
		void assign_emps(Employee *e1, Employee *e2)
		{
			emp1=e1;
			emp2=e2;
			cout<<" Employees Assigned to "<<dept_name<<" Department. "<<endl;
		}
		
		void display_employees()
		{
			cout<<dept_name<<" Department has : "<<endl;
			if(emp1)
			{
				emp1->display();
			}
			
			if(emp2)
			{
				emp2->display();
			}
		}
		
};

int main()
{
	
    Employee *e1= new Employee(" Ali ");
    Employee *e2= new Employee(" Ahmad ");

    
        Department hr(" HR ");
        Department it(" IT ");

        hr.assign_emps(e1, e2);
        it.assign_emps(e2, e1);

        hr.display_employees();
        it.display_employees();

    cout<<" Employees still exist after departments are destroyed! "<<endl;
    
    e1->display();
    e2->display();

    delete e1;
    delete e2;

    return 0;
}
