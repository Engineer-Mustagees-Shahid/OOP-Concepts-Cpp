#include<iostream>
#include<string>
using namespace std;

class Logger{
	
    private:
		
        static string logs[10]; 
        static int count;

    public:
    	 
        static void msgs(const string &message)
	{
            if(count<10) 
		   {
                logs[count]=message;
                count++;
           } 
		    else 
		{
            cout<<"Log message storage full we cannot add more messages."<<endl;
        }
    }

    static void print_msgs() 
	{
        cout<<endl<<"--- Stored Log Messages are ---"<<endl<<endl;
        for(int i=0; i<count; i++)
		{
            cout<<i+1<<" "<<logs[i]<<endl;
        }
    }
};

string Logger::logs[10]; 
int Logger::count=0;    

int main()
{
	Logger log;
    log.msgs("I am Mustagees Shahid.");
    log.msgs("I'm 21 years old.");
    log.msgs("I'm from Burewala District Vehari.");
    log.msgs("We are in 2nd Semmester.");
    log.msgs("And learning OOP.");

    log.print_msgs();

    return 0;
}
