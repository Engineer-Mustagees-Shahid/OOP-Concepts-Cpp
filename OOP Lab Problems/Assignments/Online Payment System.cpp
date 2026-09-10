#include<iostream>
#include<string>

using namespace std;

class User{   // Abstract Class maens to hide the data of the User.
	
	protected:
		
		string name;
		string email;
		double wallet_balance;
	
	public:
		
		User(const string &name, const string &email, double balance)
		{
			this->name=name;
			this->email=email;
			wallet_balance=balance;
		}
		
		void add_money(double amount)
		{
			wallet_balance+=amount;
			cout<<"\n Amount is added. Now new Balance is : "<<wallet_balance<<endl;
		}
		
		virtual void display_Profile() const=0;
		
		virtual ~User() {}
	
};

class Buyer: public User{    // Concrete Inherit class (Buyer(Inherit))
	
	private:
		
		string purchase_history[10];
		int purchase_count;
		
	public:
		
		Buyer(const string &name, const string &email, double balance) : User(name,email,balance)
		{
			purchase_count=0;
		}
		
		void add_Purchase(const string &item)
		{
			if(purchase_count<10)
			{
				purchase_history[purchase_count++]=item;
			}
			
			else
			{
				cout<<"\n Purchase history is full. "<<endl;
			}
		}
		
		void display_Profile() const
		{
		    cout<<" ----- Buyer Profile -----" << endl;
            cout<<" Name: " <<name<<endl;
            cout<<" Email: " <<email<<endl;
            cout<<" Wallet Balance: $" <<wallet_balance<<endl;
            cout<<" Purchase History: "<<endl;
            
            if(purchase_count==0)
            {
            	cout<<"\n No Purchase. "<<endl;
			}
			
			else 
			{
				for(int i=0; i<purchase_count;i++)
				{
					cout<<purchase_history[i]<<" ";
				}
				cout<<endl;
			}
			
			cout<<"-------------------------"<<endl;
		}
	
};

class Seller : public User{  // Concrete Class inherited by User
	
	private:
		
		string sale_history[10];
		int sale_count;
		
	public:
		
		Seller(const string &name, const string &email, double balance) : User(name,email,balance)
		{
			sale_count=0;
		}
		
		void add_sale(const string &item)
		{
			if(sale_count<10)
			{
				sale_history[sale_count++]=item;
			}
			
			else
			{
				cout<<"\n Sale history is full. "<<endl;
			}
		}
		
		void display_Profile() const
		{
		    cout<<" ----- Seller Profile -----" << endl;
            cout<<" Name: " <<name<<endl;
            cout<<" Email: " <<email<<endl;
            cout<<" Wallet Balance: $" <<wallet_balance<<endl;
            cout<<" Selling History: "<<endl;
            
            if(sale_count==0)
            {
            	cout<<"\n No sale. "<<endl;
			}
			
			else 
			{
				for(int i=0; i<sale_count;i++)
				{
					cout<<sale_history[i]<<" ";
				}
				cout<<endl;
			}
			
			cout<<"-------------------------"<<endl;
		}
		
}; 

class Payment_Method{   //Interface class 
	
	public:
		
		virtual void pay(double amount)=0;
		virtual ~Payment_Method() {}
};

class Credit_Card_Payment : public Payment_Method{  // Concrete class that is inherited by the interface class
	
	public:
		
		void pay(double amount)
		{
			cout<<" Payment of $ " <<amount<<" made successfully using Credit Card. "<<endl;
		}
		
};

int main()
{
	Buyer *buyer= new Buyer("Ali","ali124@gmail.com",100);
	Seller *seller= new Seller("Ahmad","ahmad123@gmail.com",65);
	
	buyer->add_Purchase("Laptop");
	buyer->add_Purchase("HeadPhones");
	
	seller->add_sale("Mobile");
	
	buyer->display_Profile();
	seller->display_Profile();
	
	buyer->add_money(100.0);
	seller->add_money(80.0);
	
	Credit_Card_Payment credit;
	credit.pay(80);
	
	delete buyer;
    delete seller;
	
	return 0;
}



