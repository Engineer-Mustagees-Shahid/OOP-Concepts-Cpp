#include<iostream>
#include<string>
using namespace std;


void checking(string,string,int);

int main()
{
  string str_1,str_2;
  int length;
  cout<<" Enter string 01 :";
  cin>>str_1;
  length= str_1.length();
  cout<<endl<<" Enter the string 02 :";
  cin>>str_2;
  
  checking(str_1,str_2,length);
	
	return 0;
}


void checking( string str_1 , string str_2, int length)
{
	for (int i=0; i<length/2; i++)
	{
		char temp=str_1[i];
		str_1[i]=str_1[length-1-i];
		str_1[length-1-i]=temp;
	}
	
	if(str_1==str_2)
	{
		cout<<endl<<" The two strings are revere to each other ";
	}
	else 
	{
		cout<<endl<<" The two strings are not reverse to each other ";
	}
	
}