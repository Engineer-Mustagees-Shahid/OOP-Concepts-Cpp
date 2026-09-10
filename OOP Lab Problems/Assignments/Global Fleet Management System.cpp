#include<iostream>
#include<string>
#include<ctime>

using namespace std;

struct Vehicle{
	
    int id;
    float fuel_level;
    Vehicle *next;
    time_t last_update;

    Vehicle(int id, float fuel_level)
	{
        this->id=id;
        this->fuel_level=fuel_level;
        this->last_update=time(nullptr);
        this->next=nullptr;
    }
};

struct Region{
    string name;
    Vehicle *head;
    Region *next;

    Region(string name)
	{
        this->name=name;
        this->head=nullptr;
        this->next=nullptr;
    }
};

struct Fleet_manager{
	
    Region *head;

    Fleet_manager()
	{
        this->head=nullptr;
    }

    void add_region(const string &name)
	{
        Region *new_region= new Region(name);
        new_region->next=head;
        head=new_region;
    }

    void add_vehicle(const string &region_name, int id, float fuel_level)
	{
        Region *region=head;

        while(region!=nullptr)
		{
            if(region->name == region_name)
			{
                break;
            }
            region=region->next;
        }

        if(!region)
		{
            cout<<" Region not found! "<<endl;
            return;
        }

        Vehicle *new_vehicle= new Vehicle(id,fuel_level);
        
        insert_sorted(region,new_vehicle);
    }

    Vehicle *find_lowest_fuel_vehicle(const string &region_name)
	{
        Region *region= find_region(region_name);
        
        return(region && region->head) ? region->head : nullptr;
    }

    void remove_inactive_vehicles(double hours)
	{
        time_t current_time=time(nullptr);
        
        Region *region=head;

        while(region)
		{
            Vehicle *previous= nullptr;
            Vehicle *current= region->head;

            while(current)
			{
                double elapsed=difftime(current_time,current->last_update)/3600;
                
                if(elapsed>hours)
				{
                    Vehicle *to_delete=current;
                    
                    current=current->next;
                    
                    if(previous)
                    {
                    	previous->next=current;
					}
					    else
						{
							region->head=current;
						 } 
						 
                    delete to_delete;
                    
                }
                
				else
				{
                    previous=current;
                    current=current->next;
                }
            }
            region=region->next;
        }
    }

    void print_fleet_status()
	{
        Region *region=head;
        
        while(region)
		{
            cout<<" Region : "<<region->name<<endl;
            
            Vehicle *vehicle=region->head;
            
            while(vehicle)
			{
                cout<<"  Vehicle id :"<<vehicle->id<<" , fuel : "<<vehicle->fuel_level<<endl;
                vehicle=vehicle->next;
            }
            region=region->next;
        }
    }

        private:
        	
        	Region *find_region(const string &name)
        	{
        		Region *region=head;
        		
        		while(region)
        		{
        			if(region->name == name)
        			{
        				return region;
					}
					
					region=region->next;
				}
				
				return nullptr;
			}
			
	void insert_sorted(Region *region, Vehicle *new_vehicle)
	{
		Vehicle **current= &region->head;
		
		while(*current && (*current)->fuel_level <= new_vehicle->fuel_level)
		{
			current=&((*current)->next);
		}
		
		new_vehicle->next= *current;
		*current= new_vehicle;
	}
};

int main()
{
    Fleet_manager fm;

    fm.add_region(" East ");
    fm.add_region(" West ");
    fm.add_region(" North ");
    fm.add_region(" South ");


    fm.add_vehicle(" East ",101,40.5);
    fm.add_vehicle(" West ",104,50.5);
    fm.add_vehicle(" North ",102,25.5);
    fm.add_vehicle(" South ",103,35.5);

    cout<<" Fleet status before removal : "<<endl;
    
    fm.print_fleet_status();

    Vehicle *lowest=fm.find_lowest_fuel_vehicle(" East ");
    
    if(lowest)
	{
        cout<<endl<<" Lowest fuel vehicle in East : id "<<lowest->id<<endl;
    }

    fm.remove_inactive_vehicles(0.3);

    cout<<endl<<" After removing inactive vehicles : "<<endl;
    
    fm.print_fleet_status();

    return 0;
}
