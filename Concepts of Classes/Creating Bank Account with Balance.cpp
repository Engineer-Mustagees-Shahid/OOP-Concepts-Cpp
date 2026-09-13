#include<iostream>
using namespace std;

class Bank_Account;

class Bank_Account{
	
	private:
		
		double balance;
		
	public:
		
		Bank_Account(double initial)
		{
			balance=initial;
			cout<<" Bank Acoount is created with certain Balance  "<<endl;
		}

    friend void display_balance(const Bank_Account &account);
};


void display_balance(const Bank_Account &account)
{
    cout<<" Current Account Balance: $ "<<account.balance<<endl;
}


int main()
{
	
    Bank_Account acc_1(1500.7);
    display_balance(acc_1);

    Bank_Account acc_2(3000.0);
    display_balance(acc_2);

    return 0;
}
