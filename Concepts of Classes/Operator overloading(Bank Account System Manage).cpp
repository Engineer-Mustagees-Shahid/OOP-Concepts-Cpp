#include<iostream>

using namespace std;

class BankAccount{
	
	private:
		
		string name;
		int no;
		double balance;
		
	public:
		
		BankAccount()
		{
			name="Unknown";
			no=0;
			balance=0;
		}
		
		BankAccount(string name, int no, double bal)
		{
			this->name=name;
			this->no=no;
			balance=bal;
		}
		
		BankAccount operator+(double amount)
		{
	    	BankAccount temp;
	    	temp.name=this->name;
	    	temp.no=this->no;
			temp.balance=this->balance+amount;
			
			return temp;
		}
		
		BankAccount operator-(double amount)
		{
			if(this->balance<amount)
		{
			cout<<"\n Insufficient balance. "<<endl;
			return *this;
	    }
	    
	    else
	    {
	    	BankAccount temp;
	    	temp.name=this->name;
	    	temp.no=this->no;
			temp.balance=this->balance-amount;
			
			return temp;
		}
		
		}
		
		BankAccount &operator=(const BankAccount &obj) 
		{
			if(this!=&obj)
			{
				this->name=obj.name;
				this->no=obj.no;
				this->balance=obj.balance;
			}
			
			return *this;
		}
		
		bool operator<(const BankAccount &obj) 
		{
			if(this->balance<obj.balance)
			return true;
			
			return false;
		}
		
		friend ostream &operator<<(ostream &os, const BankAccount &obj)
		{
			os<<"\n Name : "<<obj.name<<"\n Account No : "<<obj.no<<"\n Account Balance : "<<obj.balance<<endl;
			
			return os;
		}
	
};

int main()
{
	BankAccount account1("Ali",123,5000);
	BankAccount account2("Ahmad",12345,6000);
	
	cout<<account1<<endl;
	cout<<account2<<endl;
	
	account1=account1+5000;
	cout<<account1<<endl;
	
	account2=account2-5000;
	cout<<account2<<endl;
	
	account1=account2;
	cout<<account1<<endl;
	
	if(account1<account2)
	{
		cout<<"\n Account 2 has more money. "<<endl;
	}
	else 
	{
		cout<<"\n Account 1 has mmore money."<<endl;
	}
	
	
	return 0;
}