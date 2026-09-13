#include<iostream>

using namespace std;

class StudentGrade{
	
	
	private:
		
		int grade[5];
		
	public:
		
		StudentGrade()
		{
			for(int i=0;i<5; i++)
			{
				grade[i]=0;
			}
		}
		
		int &operator[](int index)
		{
			if(index<0 || index>=5)
			{
				cout<<"\n Invalid Array is out of bound."<<endl;
				return grade[0];
			}
			
			return grade[index];		
		}
		
		void display()
		{
			for(int i=0;i<5; i++)
			{
				cout<<grade[i]<<endl;
			}
		}
};

int main()
{
	StudentGrade st;
	
	int index, value;
	
	for(int i=0; i<5;i++)
	{
		cout<<"\n Enter the index : ";
		cin>>index;
		if(index<0 || index>=5)
		{
			cout<<"\n Array is out of bond. "<<endl;
			--i;
			continue;
		}
		cout<<"\n Enter the value: ";
		cin>>value;
		
		st[index]=value;
	}
	
	st.display();
	
	return 0;
}