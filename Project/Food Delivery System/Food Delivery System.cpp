#include<iostream>
#include<fstream>    // For File Handling
#include<string>
#include<ctime>     // For Time (it is used in to save the history in file handling)
#include<utility>  // For Pair Function
#include<conio.h>
#include<limits>

using namespace std;


// class Menue for manage the menue 

class Menu{
	
	private:
		
		static const int max_items=100;
		string items[max_items];
		double prices[max_items];
		int item_count;

		
	public:
		
		Menu()
		{
			item_count=0;
		}
		
	//  function for load menu to the Ram again if the user close the console and then open again
		
		void load_menu()
		{
			ifstream load_menu("Menu.txt");
			
            if(!load_menu.is_open())
		{
            cerr<<" Error: Menu.txt file not found or inaccessible! "<<endl;
            return;		
	    }
	    
			if(load_menu.is_open())
			{
					item_count=0;
					string name;
					double price;
					
					while(load_menu >> name >> price && item_count<max_items)
					{
						items[item_count]=name;
						prices[item_count]=price;
						item_count++;
					}
					
					load_menu.close();
			}
			else
			{
				cerr<<"\n Unable to open Menu File(Because there is no menue file exist, First Owner create) "<<endl;
			}
		}
		
	// Checking the item that is it already exist or not	
		
		bool item_exist_in_file(const string &item_name)
		{
			for(int i = 0; i < item_count; i++)
			 {
				if(items[i] == item_name)
				 {
					return true;
				}
			}
			return false;
		}
		
	// function add_item is used to add the addditional item in the shoop by the Owner
		
		void add_item(const string &name, double price)
		{
			if(item_exist_in_file(name))
			{
				cout<<"\n Item already exist. "<<endl;
				return;
			}
			
			if(item_count<max_items)
			{
				items[item_count]=name;
				prices[item_count]=price;
				item_count++;
				cout<<"\n Item is Added : "<<name<<"  Rs "<<price<<endl;
				
				ofstream Menu_file("Menu.txt", ios::app);
				
                if(!Menu_file)
			    {
                    cerr<<" Error: Failed to save item in file! "<<endl;
                    return;
                }				
					
				if(Menu_file.is_open())
				{
					Menu_file<<name<<" "<<price<<endl;
					Menu_file.close();
				}
				
				else
				{
					cerr<<"\n Item is not included. "<<endl;
				}
			}
			else
			{
				cout<<"\n Menu is full Cannot add more items. "<<endl;
			}
		}
	
	
	// Function to remove the item it only acessible by the Owner
		
		void remove_item(const string &name)
		{
			load_menu();
			bool found=false;
			
			for(int i=0; i<item_count; i++)
			{
				if(items[i]==name)
				{
					for(int j=i; j<item_count-1 ;j++)
					{
						items[j]=items[j+1];
						prices[j]=prices[j+1];
					}
					
					item_count--;
					found=true;
					break;
				}
			}
					
			if(found)
			{
				ofstream update_file("Menu.txt");
				
				if(update_file.is_open())
				{
					for(int i=0; i<item_count; i++)
					{
						update_file<<items[i]<<" "<<prices[i]<<endl;
					}
					
					update_file.close();
					cout<<"\n Item "<<name<<" is removed. "<<endl;
				}
				else
				{
					cerr<<"\n Unable to update."<<endl;
				}
			}
			else
			{
				cout<<"\n Item not found. "<<endl;
			}
		}
						
	// function update_item is used for update the item price which are already availabe in the stock
		
		void update_item(const string &name, double new_price)
		{
			if(new_price<=0)
			{
                cerr<<" Error: Price must be positive! "<<endl;
                return;
            }
			
			load_menu();
			bool found=false;
			
			for(int i=0; i<item_count; i++)
			{
				if(items[i]==name)
				{
					prices[i]=new_price;
					found=true;
					break;
				}
			}      
		    
			if(found)
		    {
		    	ofstream update_file("Menu.txt");
		    	
		    	if(update_file.is_open())
		    	{
		    		for(int i=0; i<item_count; i++)
		    		{
		    			update_file<<items[i]<<" "<<prices[i]<<endl;
					}
					update_file.close();
					cout<<"\n Update Successfully. "<<endl;
				}
				else
				{
					cerr<<"\n Failed to update. "<<endl;
				}
			}
			else
			{
				cout<<"\n Item is not found. "<<endl;
			}
		}
				
	// display_menu_from_file function is used to display the additional items menue that owner manage for the user to order
		
		void display_menu_from_file() const
		{
			ifstream menu_file("Menu.txt");
			if(!menu_file.is_open())
			{
				cerr<<"\n Unable to open (May be Not Exist, So First file is created then you watch the menue). "<<endl;
				return;
			}
			
			cout<<"\n ---------------------------------Menu------------------------------"<<endl;
			string name;
			double price;
			int count=0;
			
			while(menu_file>>name>>price && count< max_items)
			{
				cout<<" "<<count+1<<" . "<<name<<" $ "<<price<<endl;
				count++;
			}
			
			if(count==0)
			{
				cout<<"\n Menu is Empty "<<endl;
			}
			
			menu_file.close();
		}
		
		int get_item_count() const
		{
			return item_count;
		}
};

// Class For Authentication of the User and Owner

class User_Authentification{
	
	private:
		
		string user_mail, user_password, user_role;
		
		string Private_Password() 
	{
        string password;
        
        char ch;
        
        while((ch=getch()) != '\r')
		{                                    // '\r' is the Enter key
            if (ch=='\b')
			{                               // Handle backspace
                if (!password.empty())
				{
                    cout<<"\b \b";          // Erase the last asterik
                    password.pop_back();
                }
            }
            else
			{
                password.push_back(ch);
                cout<<'*';                  // Show asterik instead of the actual character
            }
        }
        cout<<endl;
        return password;
    }
		
	public:
		
	// Function For User Registration
		
		void user_register()
		{
			cout<<"\n Enter your E-Mail : ";
			cin>>user_mail;
			
			if(user_mail.empty() || user_mail.find('@')==string::npos || user_mail.find(".com")==string::npos)
			{
				cout<<"\n Error : 'Email must contain @ , .com' And with Correct Format. "<<endl;
				return;
			}
			
			ifstream check_file("User.txt");
			string mail,pass,role;
			
			while(check_file>>mail>>pass>>role)
			{
				if(mail==user_mail)
				{
					cout<<" \n This email is already registered. Try Register with different mail. "<<endl;
					check_file.close();
					return; 
				}
			}
    
			check_file.close();
			
			cout<<"\n Enter your Password : ";
			user_password=Private_Password();
			cin.ignore();
			
			if(user_password.length()<6) 
			{
                cout<<"\n Password must be at least 6 characters! "<<endl;
                return;
            }
			
			user_role="Customer";
			
			ofstream user_register("User.txt", ios::app);
			if(user_register.is_open())
			{
				user_register<<user_mail<<" "<<user_password<<" "<<user_role<<endl;
				user_register.close();
				cout<<"\n Registration successsfully ! "<<endl;
			}
			else
			{
				cerr<<" Failed To Register "<<endl;	
			}
		}
		
	// Function For Owner Registration
		
		void owner_register()
		{
			string owner_mail,owner_password,owner_role;
			
			ifstream check_owner("User.txt");
			string o_mail,o_pass,o_role;
			
			while(check_owner>>o_mail>>o_pass>>o_role)
			{
				if(o_role=="Owner")
				{
					cout<<"\n Owner is already registered. "<<endl;
					check_owner.close();
					return;
				}
			} 
			check_owner.close();
			
			cout<<"\n Enter your E-mail : ";
			cin>>owner_mail;
			
			if(owner_mail.find('@')==string::npos || owner_mail.find(".com")==string::npos)
			{
				cout<<"\n Error : 'Email must contain @ , .com' "<<endl;
				return;
			}
			
			ifstream check_file("User.txt");
			string mail,pass,role;
			
			while(check_file>>mail>>pass>>role)
			{
				if(mail==owner_mail)
				{
					cout<<" \n This email is already registered. Try logging in instead. "<<endl;
					check_file.close();
					return; 
				}
			}
    
			check_file.close();
			
			cout<<"\n Enter your Password : ";
			owner_password=Private_Password();
			
			if(user_password.length()<6) 
			{
                cout<<"\n Password must be at least 6 characters! "<<endl;
                return;
            }
			
			owner_role = "Owner";
			
			ofstream user_register("User.txt", ios::app);
			if(user_register.is_open())
			{
				user_register<<owner_mail<<" "<<owner_password<<" "<<owner_role<<endl;
				user_register.close();
				cout<<"\n Registration successsfully.... ! "<<endl;
			}
			else
			{
				cerr<<" Failed To Register.... "<<endl;
			}
		}
		
		
	// Making Pair Function For the Login
		
		pair<string,string> login_user()
		{
			string mail,password,role;
			
			cout<<"\n Enter your E-Mail : ";
			cin>>mail;
			
			cout<<"\n Enter your Password : ";
			password=Private_Password();
		
			ifstream login_user("User.txt");
			if(login_user.is_open())
			{
				while(login_user>>user_mail>>user_password>>user_role)
			    {
					if(mail==user_mail && password==user_password)
					{
						cout<<"\n Login Successfully.... "<<endl;
					    login_user.close();
					    return {user_role,mail};
					}
			    }		

				login_user.close();	
		    }
				
			return {"Access Denied.",""};
		}
};

// Making Customer class to perform  operations like to browse menu, order the items, to watch history

class Customer{
	
    public:
    	
    	void customer_menu(const string &mail, Menu &menu)
		{
			int choice;
			
        do{
            cout<<" \n------------------ Customer Menu ------------------"<<endl;
            cout<<" 1. Browse Menu "<<endl;
            cout<<" 2. Place Pizza's Order "<<endl;
            cout<<" 3. Order Additional Item "<<endl;
            cout<<" 4. Watch Order History "<<endl;
            cout<<" 5. Logout "<<endl;
            
            cout<<"\n Enter your choice: ";
            
                while (!(cin>>choice) || choice<1 || choice>5) 
				{
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }           


            switch(choice)
			{
                case 1:
                    cout <<"\n\t\t\t [Browsing Menu...] "<<endl;
                    menu.display_menu_from_file();
                    break;

                case 2:
                    cout<<"\n\t\t\t [Placing Order...]" <<endl;
                    cout<<"\n\n\t\t\t These Items are always available in our food Shop. "<<endl;
                    cout<<"\n To Place Order Select the Items : "<<endl;
                    cout<<"\n Firstly Select the Pizza Flavour : "<<endl;
                    cout<<"\n For Tikka Enter 'T' "<<endl;
                    cout<<"\n For Fajita Enter 'F' "<<endl;
                    cout<<"\n For Special Enter 'S' "<<endl;
                    
                    char choice_flavour;
					
                    cout<<"\n Enter Your favourite Flavour of Pizza : ";
                    cin>>choice_flavour;
                    choice_flavour = toupper(choice_flavour);
                    
                    switch(choice_flavour)
                    {
                    	case 'T':
                    		cout<<"\n Tikka "<<endl;
                    		{
                    			char choice_size;
                    			
                    			cout<<"\n Secondly Select the Pizza's Size : "<<endl;
                                cout<<"\n For Small Enter 'S' "<<endl;
                                cout<<"\n For Medium Enter 'M' "<<endl;
                                cout<<"\n For Large Enter 'L' "<<endl;
                                cout<<"\n For X-Large Enter 'X' "<<endl;
                                
                    			cout<<"\n Enter the size : ";
                    			cin>>choice_size;
                    			choice_size = toupper(choice_size);
                    			
                    			switch(choice_size)
                    			{
                    				case 'S':
                    					{
										                    					
                    						ofstream User_Order_list((mail + "Order.txt").c_str(), ios::app);
                    					
                    						if(User_Order_list.is_open())
                    						{
                    							cout<<"\n Flavour: Tikka"<<" Size: Small "<<" Rs.600 "<<endl;
                    					        cout<<"\n Your Order is Confirm Succeessfully. Thanks! "<<endl;
                    					        User_Order_list<<"Flavour: Tikka "<<" Size: Small "<<" Rs.600 "<<endl;
                    					        time_t now=time(0);
                                                char *dt=ctime(&now);
                    					        User_Order_list<<"Order Placed At: " <<dt<<endl;
                    					        User_Order_list.close();
											}
											cout<<"\n Your Order History is Saved. "<<endl;
										break;
										}
										
                    				case 'M':
                    					{
                    						ofstream User_Order_list((mail + "Order.txt").c_str(), ios::app);
                    						
                    						if(User_Order_list.is_open())
                    						{
                    							cout<<"\n Flavour: Tikka"<<" Size: Medium "<<" Rs.1100 "<<endl;
                    					        cout<<"\n Your Order is Confirm Succeessfully. Thanks! "<<endl;
                    					        User_Order_list<<"Flavour: Tikka "<<" Size: Medium "<<" Rs.1100 "<<endl;
                    					        time_t now=time(0);
                                                char *dt=ctime(&now);
                    					        User_Order_list<<"Order Placed At: " <<dt<<endl;
                    					        User_Order_list.close();
											}
											
											cout<<"\n Your Order History is saved. "<<endl;
											break;
										}

                    				case 'L':
                    					{
                    						ofstream User_Order_list((mail + "Order.txt").c_str(), ios::app);
                    						
                    						if(User_Order_list.is_open())
                    						{
                    							cout<<"\n Large "<<" Rs.1500 "<<endl;
                    					        cout<<"\n Your Order is Confirm Succeessfully. Thanks! "<<endl;
                     					        User_Order_list<<"Flavour: Tikka "<<" Size: Large "<<" Rs.1500 "<<endl;
                    					        time_t now=time(0);
                                                char *dt=ctime(&now);
                    					        User_Order_list<<"Order Placed At: " <<dt<<endl;
                    					        User_Order_list.close();                   					        
											}
											
											cout<<"\n Your Order History is saved. "<<endl;
											break;
										}
                    					
                    				case 'X':
                    					{
                    						ofstream User_Order_list((mail + "Order.txt").c_str(), ios::app);
                    						
                    						if(User_Order_list.is_open())
                    						{
                    							cout<<"\n X-Large "<<" Rs.2200 "<<endl;
                    					        cout<<"\n Your Order is Confirm Succeessfully. Thanks! "<<endl;
                    					        User_Order_list<<"Flavour: Tikka "<<" Size: X-Large "<<" Rs.2200 "<<endl;
                    					        time_t now=time(0);
                                                char *dt=ctime(&now);
                    					        User_Order_list<<"Order Placed At: " <<dt<<endl;
                    					        User_Order_list.close();
											}
											
											cout<<"\n Your Order History is saved. "<<endl;
											break;
										}
                    					
                    				default:
                    					cout<<"\n Invalid Choice "<<endl;
								}
							}
                    		break;
                    		
                    	case 'F':
                    		cout<<"\n Fajita "<<endl;
                    		{
                    			char choice_size;
                    			
                    			cout<<"\n Secondly Select the Pizza's Size : "<<endl;
                                cout<<"\n For Small Enter 'S' "<<endl;
                                cout<<"\n For Medium Enter 'M' "<<endl;
                                cout<<"\n For Large Enter 'L' "<<endl;
                                cout<<"\n For X-Large Enter 'X' "<<endl;
                                
                    			cout<<"\n Enter the size : ";
                    			cin>>choice_size;
                    			choice_size = toupper(choice_size);
                    			
                    			switch(choice_size)
                    			{
                    				case 'S':
                    					{
                    						ofstream User_Order_list((mail + "Order.txt").c_str(), ios::app);
                    					
                    						if(User_Order_list.is_open())
                    						{
                    					        cout<<"\n Flavour: Fajita Size: Small "<<" Rs.600 "<<endl;
                    					        cout<<"\n Your Order is Confirm Succeessfully. Thanks! "<<endl;
                    					        User_Order_list<<"Flavour: Fajita "<<" Size: Small "<<" Rs.600 "<<endl;
                    					        time_t now=time(0);
                                                char *dt=ctime(&now);
                    					        User_Order_list<<"Order Placed At: " <<dt<<endl;
                    					        User_Order_list.close();
											}
											
											cout<<"\n Your Order History is Saved. "<<endl;
											break;
										}

                    				case 'M':
                    					{
                    						ofstream User_Order_list((mail + "Order.txt").c_str(), ios::app);
                    					
                    						if(User_Order_list.is_open())
                    						{
                    					        cout<<"\n Flavour: Fajita Size: Medium "<<" Rs.1100 "<<endl;
                    					        cout<<"\n Your Order is Confirm Succeessfully. Thanks! "<<endl;
                    					        User_Order_list<<"Flavour: Fajita "<<" Size: Medium "<<" Rs.1100 "<<endl;
                    					        time_t now=time(0);
                                                char *dt=ctime(&now);
                    					        User_Order_list<<"Order Placed At: " <<dt<<endl;
                    					        User_Order_list.close();
											}
											
											cout<<"\n Your Order History is Saved. "<<endl;
											break;
										}

                    				case 'L':
                    					{
                    						ofstream User_Order_list((mail + "Order.txt").c_str(), ios::app);
                    					
                    						if(User_Order_list.is_open())
                    						{
                    					        cout<<"\n Flavour: Fajita Size: Large "<<" Rs.1500 "<<endl;
                    					        cout<<"\n Your Order is Confirm Succeessfully. Thanks! "<<endl;
                    					        User_Order_list<<"Flavour: Fajita "<<" Size: Large "<<" Rs.1500 "<<endl;
                    					        time_t now=time(0);
                                                char *dt=ctime(&now);
                    					        User_Order_list<<"Order Placed At: " <<dt<<endl;
                    					        User_Order_list.close();
											}
											
											cout<<"\n Your Order History is Saved. "<<endl;
											break;
										}

                    				case 'X':
                    					{
                    						ofstream User_Order_list((mail + "Order.txt").c_str(), ios::app);
                    					
                    						if(User_Order_list.is_open())
                    						{
                    					        cout<<"\n Flavour: Fajita Size: X-Large "<<" Rs.2200 "<<endl;
                    					        cout<<"\n Your Order is Confirm Succeessfully. Thanks! "<<endl;
                    					        User_Order_list<<"Flavour: Fajita "<<" Size: Large "<<" Rs.2200 "<<endl;
                    					        time_t now=time(0);
                                                char *dt=ctime(&now);
                    					        User_Order_list<<"Order Placed At: " <<dt<<endl;
                    					        User_Order_list.close();
											}
											
											cout<<"\n Your Order History is Saved. "<<endl;
											break;
										}                    					

                    				default:
                    					cout<<"\n Invalid Choice "<<endl;
								}
							}
                    		break;
                    		
                    	case 'S':
                    		cout<<"\n Special "<<endl;
                    		{
                    			char choice_size;
                    			
                    			cout<<"\n Secondly Select the Pizza's Size : "<<endl;
                                cout<<"\n For Small Enter 'S' "<<endl;
                                cout<<"\n For Medium Enter 'M' "<<endl;
                                cout<<"\n For Large Enter 'L' "<<endl;
                                cout<<"\n For X-Large Enter 'X' "<<endl;
                                
                    			cout<<"\n Enter the size : ";
                    			cin>>choice_size;
                    			choice_size = toupper(choice_size);
                    			
                    			switch(choice_size)
                    			{
                    				case 'S':
                    					{
                    						ofstream User_Order_list((mail + "Order.txt").c_str(), ios::app);
                    					
                    						if(User_Order_list.is_open())
                    						{
                    					        cout<<"\n Flavour: Special Size: Small "<<" Rs.750 "<<endl;
                    					        cout<<"\n Your Order is Confirm Succeessfully. Thanks! "<<endl;
                    					        User_Order_list<<"Flavour: Special "<<" Size: Small "<<" Rs.750 "<<endl;
                    					        time_t now=time(0);
                                                char *dt=ctime(&now);
                    					        User_Order_list<<"Order Placed At: " <<dt<<endl;
                    					        User_Order_list.close();
											}
											
											cout<<"\n Your Order History is Saved. "<<endl;
											break;
										}

                    				case 'M':
                    					{
                    						ofstream User_Order_list((mail + "Order.txt").c_str(), ios::app);
                    					
                    						if(User_Order_list.is_open())
                    						{
                    					        cout<<"\n Flavour: Special Size: Medium "<<" Rs.1399 "<<endl;
                    					        cout<<"\n Your Order is Confirm Succeessfully. Thanks! "<<endl;
                    					        User_Order_list<<"Flavour: Special "<<" Size: Medium "<<" Rs.1399 "<<endl;
                    					        time_t now=time(0);
                                                char *dt=ctime(&now);
                    					        User_Order_list<<"Order Placed At: " <<dt<<endl;
                    					        User_Order_list.close();
											}
											
											cout<<"\n Your Order History is Saved. "<<endl;
											break;
										}
                    				case 'L':
                    					{
                    						ofstream User_Order_list((mail + "Order.txt").c_str(), ios::app);
                    					
                    						if(User_Order_list.is_open())
                    						{
                    					        cout<<"\n Flavour: Special Size: Large "<<" Rs.1,999 "<<endl;
                    					        cout<<"\n Your Order is Confirm Succeessfully. Thanks! "<<endl;
                    					        User_Order_list<<"Flavour: Special "<<" Size: Large "<<" Rs.1,999 "<<endl;
                    					        time_t now=time(0);
                                                char *dt=ctime(&now);
                    					        User_Order_list<<"Order Placed At: " <<dt<<endl;
                    					        User_Order_list.close();
											}
											
											cout<<"\n Your Order History is Saved. "<<endl;
											break;
										}

                    				case 'X':
                    					{
                    						ofstream User_Order_list((mail + "Order.txt").c_str(), ios::app);
                    					
                    						if(User_Order_list.is_open())
                    						{
                    					        cout<<"\n Flavour: Special Size: X-Large "<<" Rs.2799 "<<endl;
                    					        cout<<"\n Your Order is Confirm Succeessfully. Thanks! "<<endl;
                    					        User_Order_list<<"Flavour: Special "<<" Size: X-Large "<<" Rs.2799 "<<endl;
                    					        time_t now=time(0);
                                                char *dt=ctime(&now);
                    					        User_Order_list<<"Order Placed At: " <<dt<<endl;
                    					        User_Order_list.close();
											}
											
											cout<<"\n Your Order History is Saved. "<<endl;
											break;
										}

                    				default:
                    					cout<<"\n Invalid Choice "<<endl;
								}
							}
                    		break;
                    		
                    	default:
                    		cout<<"\n Invalid Choice ! "<<endl;		
					}
					
                    break;
                    
                case 3:
                	{
                		char choice;
                		cout<<"\n\t\t Can you want to order additional Items (y/n): ";
                		cin>>choice;
                		choice=toupper(choice);
                		if(choice=='Y')
                		{
                			place_order_from_file(mail);
						}
					}
                	break;

                case 4:
                    cout<<" \n [Watch History...] (Here your Order History.) "<<endl;
                    track_Order(mail);
                    break;

                case 5:
                    cout<<" \n Logging out..." <<endl;
                    return;

                default:
                    cout<<" \nInvalid choice! Please select again. "<<endl;
            }
        } while (true);
    }
        
// Make the track_order Function for User to Watch the History of order he placed      
        
    void track_Order(const string &mail)
	{
		ifstream order_File((mail + "Order.txt").c_str());
	    if(!order_File)
		 {
            cout<<" No order history found. "<<endl;
            return;
         }
		
	    cout<<" \n === Order History === "<<endl;
        string line;
         while (getline(order_File, line))
         {
         	cout<<line<<endl;
		 }
		 
		 order_File.close();	 
	}
	
// Place_order_from_file function is used to order adiitional items which the owner add to their food shoop
	
	void place_order_from_file(const string &mail)
	{
		string item_name;
		cout<<"\n Enter the Item name you want to order : ";
		cin.ignore();
		getline(cin,item_name);
		
		ifstream update_user_order_list("Menu.txt");
		string name;
		double price;
		bool found=false;
		
		while(update_user_order_list>>name>>price)
		{
			if(name==item_name)
			{
				found=true;
				cout<<"\n Item found "<<name<<" Rs "<<price<<endl;
				
				char confirm;
				cout<<"\n Do you want to confirm the item for Order (y/n): ";
				cin>>confirm;
				confirm=toupper(confirm);
				
				if(confirm=='Y')
				{
					ofstream user_order((mail + "Order.txt").c_str(), ios::app);
					if(user_order.is_open())
					{
						user_order<<"Item: "<<name<<" price: "<<price<<" Rs "<<endl;
						time_t now=time(0);
						char *dt=ctime(&now);
						user_order<<"Order Placed At: " <<dt<<endl;
						user_order.close();
						cout<<"\n Order is placed Succeessfully ! "<<endl;
					}
					
					else
					{
						cout<<"\n Order is not confirm. "<<endl;
					}
				}
				
				break;
			}
		}
		
		update_user_order_list.close();
			
	    if(!found)
        {
            cout<<" \n Item does not exist." <<endl;
        }
	}
};

// class Owner for performing different operations like to manage the menue, (add,remove,update) the items

class Owner{
	
	private:
		
		Menu menu;       // Used the concept of aggregation in which Owner acess to the menue but menu is also independentally
		
	public:
		
    // Function for manage the menu by the owner
		
		void manage_menu()
		{
			menu.load_menu();
			int choice;
			string name;
			double price;
			
			do{
				cout<<"\n Owner Menu ->> Manage your restaurant's menu "<<endl<<endl;
                cout<<" 1. Display "<<endl;
                cout<<" 2. Add Item "<<endl;
                cout<<" 3. Remove Item "<<endl;
                cout<<" 4. Update Item Price "<<endl;
                cout<<" 5. Logout "<<endl;
                
                cout<<"\n Enter your choice : ";
                
                while (!(cin>>choice) || choice<1 || choice>5) 
				{
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout<<"\n Invalid input! "<<"\n Enter (1-5) : ";
                
                }
                
                cin.ignore();
                
                switch(choice)
                {
                	case 1:
                		menu.display_menu_from_file();
                		break;
                		
                	case 2:
                		cout<<"\n Enter the item name (Hint: Don't use spaces) : ";
                		getline(cin,name);
                		cout<<"\n Enter Price of Item : ";
                		cin>>price;
                		cin.ignore();
                		menu.add_item(name,price);
                		break;
                	
                	case 3:
                		cout<<"\n Enter Item name to remove : ";
                		getline(cin,name);
                		menu.remove_item(name);
                		break;
                	
					case 4:
						cout<<"\n Enter name to update : ";
						getline(cin,name);
						cout<<"\n Enter price to update : ";
						cin>>price;
						cin.ignore();
						menu.update_item(name,price);
						break;
						
					case 5:
						cout<<"\n Logging Out..... "<<endl;
						return;
						
					default:
						cout<<"\n Invalid Choice. "<<endl;
				}
			}while(true);
		}
		
		Menu &get_menu()
		{
			return menu;
		}
};


// Main Function For Running Program According to their Choice

int main()
{
	User_Authentification authen;   // Authentication object
	Customer customer;              // Customer object
	Owner owner;                    // Owner object
	
	int choice;
	string role;
	
	do                           // Use of Do-while for that whenever user want's to run the programrather then choose case of exit 
	{
		cout<<"\n----------------------------------------------------- Welcome in our Food Shop !  *_* -------------------------------------------- "<<endl;
		cout<<"\n Enter '1' for User Registration:\n Enter '2' for Owner Registration:\n Enter '3' for Login:\n Enter '4' for Exit: "<<endl;
		cout<<"\n Enter your choice : ";
        while (!(cin>>choice) || choice<1 || choice>5) 
	    {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
        }
		
		// Applying Switch Statement for Different casses according to the choice
		
		switch(choice)
		{
			case 1:
				authen.user_register();
				break;
			case 2:
				authen.owner_register();
				break;
			case 3:
			{	
				pair<string,string> result;
				result=authen.login_user();
				role=result.first;
				string user_mail=result.second;
				
				if(role=="Customer")
				{
					cout<<"\n ------------------------------------------------------------------ "<<endl;
					cout<<"\n << Welcome Customer! You can now browse the menu, place orders, and Watch Order History >> "<<endl;
					customer.customer_menu(user_mail,owner.get_menu());
				}
				else if(role=="Owner")
				{
					cout<<"\n ------------------------------------------------------------------ "<<endl;
					cout<<"\n << Welcome Owner! You can manage your restaurant's menu >> "<<endl;
					owner.manage_menu();
				}
				else 
				{
					cout<<"\n Access Denied  "<<endl;
				}
				break;	
			}
			
			case 4:
				cout<<"\n ->>>Exiting from the system. "<<endl;
				return 0;
				
			default:
				cout<<"\n  Try Again "<<endl;
		}
	} while(true);
	
	return 0;
}