#include<iostream>
#include<cstring>

using namespace std;
void modifying(char *);

int main()
{
	int rows=5;
	
	const char *original[] = {"Read", "Bear", "Hat", "beat", " "};
	
	char **str= new char*[rows];
	
	for(int i=0; i<rows; i++)
	{
		str[i]= new char[strlen(original[i]+1)];
	}
	
	for(int i=0; i<rows; i++)
	{
		strcpy(str[i],original[i]);
	}
	
	for(int i=0;i<rows;i++)
	{
		modifying(str[i]);
	}
	
	cout<<" Modifying 2D String array is : ";
	
	for (int i=0; i<rows; i++)
	{
		cout<<str[i]<<" ,   ";
	}
	
	int total_characters=0;
	
	for (int i=0; i<rows; i++)
	{
		total_characters+=strlen(str[i]);
	}
	
	cout<<endl<<" Total Characters are : "<<total_characters<<endl;
	
	
	return 0;
}

void modifying (char *str)
{
	if(strlen(str)==0)
	return;
	
	switch (str[0])
	{
		case 'R':
			str[0]='B';
			break;
		case 'B':
			str[0]='R';
			break;
		case 'H':
			str[0]='B';
			break;
		case 'b':
			str[0]='H';
			break;
		default:
			break;
	}
}