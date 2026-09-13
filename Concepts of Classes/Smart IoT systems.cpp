#include<iostream>
#include<string>

using namespace std;


class Device{
	
    protected:
    	
        string device_name;
        bool power_status;
        string location;

    public:
    	
    	Device()
    	{
    		device_name=" Unknown ";
    		location=" Unknown ";
    		power_status=false;
		}
		
    	Device(string name, string loc)
		{
			device_name=name;
			location=loc;
			power_status=false;
		 }
		 
		void turn_on()
		{
			power_status=true;
			cout<<" The "<<device_name<<" is turned On now !"<<endl;
		}
		
		void turn_off()
		{
			power_status=false;
			cout<<" The "<<device_name<<" is turned Off now !"<<endl;
		}
		
		void show_status()
		{
			cout<<" Device : "<<device_name<<endl<<"  Loctaion : "<<location<<endl<<" Status : "<<(power_status ? "On":"Off")<<endl;
		}
};

class smart_light : public Device{
	
	private:
		
		int brightness;
		string color;
		
	public:
		
		smart_light()
		{
			brightness=50;
			color="Blue";
		}
		
		smart_light(string name, string location, int brightness, string color) : Device(name,location)
		{
			this->brightness=brightness;
			this->color=color;
		}
		
		void adjust_brightness_level(int level)
		{
			if(level>=0 && level<=100)
			{
				brightness=level;
				cout<<" Device : "<<device_name<<" brightness set to : "<<brightness<<" % "<<endl;
			}
			
			else
			{
				cout<<"Invalid Brightness Entered"<<endl;
			}
			
		}
		
		void change_color(string new_color)
		{
			color=new_color;
			cout<<" Device : "<<device_name<<endl<<" color changed to the color : "<<color<<endl;
		}
			
};

class smart_thermostat : public Device{
	
	private:
		
		float temperature;
		string mode;
	
	public:
		
		smart_thermostat()
		{
			temperature=23;
			mode="Auto";
		}
		
		smart_thermostat(string name, string location, float temperature, string mode) : Device(name,location)
		{
			this->temperature=temperature;
			this->mode=mode;
		}
		
		void set_temperature(float temp)
		{
			temperature=temp;
			if(temp<18)
			{
				switch_mode("Heat");
			}
			cout<<" The "<<device_name<<" set to temperature "<<temp<<endl;
		}
		
		void switch_mode(string new_mode)
		{
			mode=new_mode;
			cout<<" The thermostat switches to "<<new_mode<<" Automatically !"<<endl;
		}
	
	
};

class smart_security_camera : public Device{
	
	private:
		
		string resolution;
		bool recording_status;
		
	public:
		
		smart_security_camera()
		{
			resolution= "Auto";
			recording_status=false;
		}
		
		smart_security_camera(string name, string location, string resolution, bool recording_status) : Device(name,location)
		{
			this->resolution=resolution;
			this->recording_status=recording_status;
		}
		
		void start_recording()
		{
			recording_status=true;
			cout<<" The "<<device_name<<" is set to record at resolution"<<resolution<<endl;
		}
		
		void stop_recording()
		{
			recording_status=false;
			cout<<" The "<<device_name<<" is set to be stopped !"<<endl;
		}
		
		void view_feed()
		{
			cout<<" The live feed from  "<<device_name<<" at resolution of  "<<resolution<<endl;
		}
	
};

int main()
{
    smart_light kitchen_light(" Kitchen Light "," Kitchen ", 30 , " Brown " );
    kitchen_light.turn_on();
    kitchen_light.adjust_brightness_level(50);
    kitchen_light.change_color("blue");
    kitchen_light.show_status();
    
    cout<<"\n----------------------------"<<endl;
    
    smart_thermostat hotel_thermo(" Hotel Thermostat ", " Marquee ", 30 , "cool");
    hotel_thermo.turn_on();
    hotel_thermo.set_temperature(25);
    hotel_thermo.switch_mode(" Moderate ");
    hotel_thermo.show_status();

    
    cout<<"\n----------------------------"<<endl;
    
    smart_security_camera hotel_camera(" Enterence Camera ", " Main Door front to Hall ", " 1080p ",false);
    hotel_camera.turn_on();
    hotel_camera.start_recording();
    hotel_camera.view_feed();
    hotel_camera.show_status();
    hotel_camera.turn_off();
    
    return 0;
}
