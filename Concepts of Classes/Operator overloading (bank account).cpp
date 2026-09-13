#include<iostream>

using namespace std;

class Bankaccount{
	
	private:
		
		double balance;
		
	public:
		
		Bankaccount()
		{
			balance=0;
		}
		
		Bankaccount(double bal)
		{
			balance=bal;
		}
		
		Bankaccount operator+(const Bankaccount &b)
		{
			Bankaccount temp;
			temp.balance=this->balance+b.balance;
			
			return temp;
		}
		
		Bankaccount operator-(double amount)
		{
			if(this->balance<amount)
			{
				cout<<"\n Insufficient Balance. "<<endl;
			    return *this;
			}
			
			else
			{
				Bankaccount temp;
			    temp.balance=this->balance-amount;
			    return temp;
			}
			
		}
		
		bool operator<(const Bankaccount &b) const
		{
			if(this->balance<b.balance)
			return true;
			
			return false;
		}
		
		bool operator>(const Bankaccount &b) const
		{
			if(this->balance>b.balance)
			return true;
			
			return false;
		}
		
		friend ostream &operator<<(ostream &os, const Bankaccount &b)
		{
			os<<"\n Account Balance is : "<<b.balance<<endl;
			
			return os;
		}
	
};

int main()
{
	Bankaccount acc1(5000);
	Bankaccount acc2(4000);
	
	acc1=acc1+acc2;
	cout<<acc1<<endl;
	
	acc1=acc1-3000;
	cout<<acc1<<endl;
	
	if(acc1<acc2)
	cout<<"\n The account 2 has more money than account 1 "<<endl;
	
	if(acc2<acc1)
	cout<<"\n The account 1 has more money than account 2 "<<endl;
	
	return 0;
}