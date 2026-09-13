#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int size,len_1,len_2;
    cout<<" Enter the size of the string : ";
    cin>>size;
	char *str_1= new char[size];
	cout<<" Enter the First String : ";
	cin>>str_1;
	len_1=strlen(str_1);
	char *str_2= new char [size];
	cout<<" Enter the Second String : ";
	cin>>str_2;
	len_2=strlen(str_2);
	if(len_1!=len_2)
	{
		cout<<" strings are not reverse to each other."<<endl;
		return 0;
	}
	else 
	{
       
       bool is_reverse= true;
       
	for (int i=0; i<len_1/2; i++)
	{
		if(str_1[i]!=str_2[len_2-i-1])
		{  
			is_reverse= false;
			break;
		}
	}
	
	if(is_reverse)
	{
	    cout<<" The strings are reverse to each other.";
	}
	else 
	cout<<" The strings are not reverse.";
	
 }
	delete [] str_1;
	str_1= NULL;	
	delete [] str_2;
	str_2= NULL;
	
	return 0;
}