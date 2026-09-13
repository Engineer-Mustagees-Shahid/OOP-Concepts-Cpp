#include<iostream>
#include<string>
using namespace std;

class Encryptor;

class Message{
	
	private:
		
		string content;
		string key;
		
	public:
		
		Message(string txt, string key)
		{
			content=txt;
			this->key=key;
		}

    friend class Encryptor;
};

class Encryptor{
	
	public:
		
		void encrypt(Message &msg)
		{
			for(char &c : msg.content)
			{
				c=c+1;
			}
			cout<<" Message is encrypted. "<<endl;
		}

    void display_encrypted(const Message &msg)
	{
        cout<<" Encrypted Message is  " <<msg.content<<endl;
    }
    
    void decrypt(Message &msg,string key)
    {
    	if(msg.key==key)
    	{
    		for(char &c : msg.content )
    	  {	
    		c=c-1;
		  }
    	    cout<<"\n Message is decrypted."<<endl;
		}

	}
};

int main()
{
	string key;
	
    Message my_message("HelloWorld","1234");

    Encryptor encryp;
    encryp.encrypt(my_message);
    encryp.display_encrypted(my_message);
    
    cout<<"\n Enter the key : ";
    getline(cin,key);
    
    encryp.decrypt(my_message,key);
    encryp.display_encrypted(my_message);

    return 0;
}
