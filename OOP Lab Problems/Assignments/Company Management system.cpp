#include<iostream>
#include<string>
using namespace std;

class Employee{      // Base Class
	
	protected:
		
		string name;
		double salary;
		
	public:
		
		Employee(const string &name, double salary)
		{
			this->name=name;
			this->salary=salary;
		}
		
		virtual void calculate_bonus() const =0;  // Pure Virtaul Function (Runtime-Polymorphism Concept)
		
		virtual void display() const
		{
			cout<<"\n Name: "<<name<<"\n Salary: "<<salary<<" $ "<<endl;
		}
		
		virtual ~Employee() {}
			
};

class Manager : public Employee{    // Derived Class Manager
	
	public:
		
		Manager(const string &name, double salary) : Employee(name,salary) {}
		
		void calculate_bonus() const     // Different bonus for Manager
		{
			cout<<" "<<name<<" 's Bonus is : "<<salary*0.20<<endl;
		}
	
};

class Engine{   // Every Engineer has Car and Car has also Engine.
	
	public:
		
		Engine()
		{
			cout<<"\n Engine is created. "<<endl;
		}
		
		void start() const 
		{
			cout<<"\n Engine is started. "<<endl;
		}
		
		~Engine()
		{
			cout<<"\n Engine is destroyed. "<<endl;
		}
	
};


class Car{    // Car class should be make because Every Engineer owns Car and Car hasengine also So, (Car also using Composition).
	
	private:
		
		Engine engine;  // Composition method
		string model;
		
	public:
		
		Car(const string &model)
		{
			this->model=model;
			cout<<"\n Car "<<model<<" is created. "<<endl;
		}
		
		void start_car()
		{
			engine.start();                               // Composition concept used.
			cout<<"\n Car is running now. "<<endl;
		}
		
		~Car()
		{
			cout<<"\n Car "<<model<<" is Destroyed. "<<endl;
		}
	
};


class Engineer : public Employee{    // Now it's time for Engineer Derived class of Employee
	
	private:
		
		Car *car;   // Composition method.
		
	public:
		
		Engineer(const string &name, double salary, const string &model) : Employee(name,salary)
		{
			car= new Car(model); // Allocated Memory for Car
		}
		
		void calculate_bonus() const
		{
			cout<<" "<<name<<" 's Bonus is : "<<salary*0.25<<" $ "<<endl;
		}
		
		~Engineer()
		{
			delete car;
		}
			
};

class Department{        // Department has multiple Employees.
	
	private:
		
		Employee *emp[10];   // Aggregation concept is used.
		int count;
		string dep_name;
		
	public:
		
		Department(const string &dep_name)
		{
			this->dep_name=dep_name;
			count=0;
		}
		
		void add_employee(Employee *emp)  // For Add the employees.
		{
			if(count<10)
			{
				this->emp[count++]=emp;
			}
			
			else
			{
				cout<<"\n Deaprtment is Full. "<<endl;
			}
		}
		
		void show_employee() const   // For Display the Employees.
		{
			cout<<"\n Dpartment : "<<dep_name<<endl;
			
			for(int i=0; i<count; i++)
			{
				emp[i]->display();
				emp[i]->calculate_bonus();
			}
		}
	
};

int main()
{
	// Creating the Employees include Manager and Engineer.
	
	Manager mngr("Ali",80000);
	Engineer engr("Ahmad",100000,"Honda Civic");
	
	// Creating Departments and Adding Employees
	
	Department dept(" Software Development ");
	dept.add_employee(&mngr);
	dept.add_employee(&engr);
	
	// Displaying Department and employees info.
	
	dept.show_employee();
	
	return 0;
}

