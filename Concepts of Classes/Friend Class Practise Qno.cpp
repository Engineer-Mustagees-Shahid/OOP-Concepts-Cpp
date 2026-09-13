#include<iostream>
#include<cstring>

using namespace std;

class Bank_Account{
	
	private:
		
		double acc_bal;
		int pin;
	
	public:
		
		Bank_Account(double bal, int pin)
		{
			acc_bal= bal;
			this->pin=pin;
		}
		
		friend class ATM;

};

class ATM{
	
	public:
		
		void check_balance(Bank_Account *bk, int pin)
		{
			if(bk->pin==pin)
			{
				cout<<"\n Your balance is : "<<bk->acc_bal<<endl;
			}
			else
			cout<<"\n Acees Denied. "<<endl;
		}
		
		void widthraw(Bank_Account *wd, int pin, double amount)
		{
			if(wd->pin==pin)
			{
				cout<<"\n Welcome in Bank. "<<endl;
				
				if(wd->acc_bal>=amount)
				{
					cout<<"\n Your transaction is successful. "<<endl;
					wd->acc_bal-=amount;
				}
				
				else 
				cout<<"\n Low Balance. "<<endl;
			}
			
			else 
			cout<<"\n Acees Denied. "<<endl;
		}
	
};

int main()
{
	Bank_Account b_k(20000.0,1234);
	Bank_Account *bk = &b_k;
	ATM atm;
	atm.check_balance(bk,1234);
	atm.widthraw(bk,1234,10000.0);

	return 0;
}