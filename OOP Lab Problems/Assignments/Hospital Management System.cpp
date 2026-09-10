#include<iostream>
#include<string>
using namespace std;

struct Doctor{
	
	string name;
	string specialization;
};

struct Patient{
	
	string name;
	int age;
	string disease;
	string gender;
	string location;
	Doctor assigned_doctor;
};

struct Hospital{
     
    string name;
    string location;
    int capacity;
	int num_of_patients;
	Patient *patients; 
};

void admit_patient(Hospital *hospital)
{
	int index=-1;
	
	for(int i=0; i<hospital->num_of_patients; i++)
	{
		if(hospital->patients[i].name== "DISCHARGED")
		{
			index=i;
			break;
		}
	}
	
	if(index==-1)
{	
      	if(hospital->num_of_patients >= hospital->capacity)
	  {
		cout<<endl<<" Hospital is full cannot add more patients ! "<<endl;
		return;
	  }	
	
	index=hospital->num_of_patients;
	hospital->num_of_patients++;
}	

    cout<<endl<<"Enter the patient name: ";
    cin>>hospital->patients[index].name;
    cout<<"Enter the age: ";
    cin>>hospital->patients[index].age;
    cout<<"Enter the disease: ";
    cin>>hospital->patients[index].disease;
    cout<<"Enter the gender :";
    cin>>hospital->patients[index].gender;
    cout<<"Enter the location of Patient :";
    cin>>hospital->patients[index].location;
    cout<<"Enter the assigned doctor's name: ";
    cin>>hospital->patients[index].assigned_doctor.name;
    cout<<"Enter the doctor's specialization: ";
    cin>>hospital->patients[index].assigned_doctor.specialization;

    cout<<endl<<"Patient admitted successfully in slot "<<index+1<<"!\n";	
}

void display_patients(Hospital *hospital)
{
	if(hospital->num_of_patients == 0)
	{
		cout<<endl<<" NO Patients admitted yet ! "<<endl;
		return;
	}
	
	cout<<endl<<" Patients in "<<hospital->name<<" are "<<endl;
	
	for(int i=0; i<hospital->num_of_patients; i++) 
	{
        if (hospital->patients[i].name == "DISCHARGED")
        {
            continue; 	
		}
        cout<<endl<<"\t Patient "<<i+1<<" : "<<endl;
        cout<<endl<<"Name : "<<hospital->patients[i].name<<endl;
        cout<<"Age : "<<hospital->patients[i].age<<endl;
        cout<<"Disease : "<<hospital->patients[i].disease<<endl;
        cout<<"Gender : "<<hospital->patients[i].gender<<endl;
        cout<<"Location : "<<hospital->patients[i].location<<endl;
        cout<<"Doctor : "<<hospital->patients[i].assigned_doctor.name<<endl;
        cout<<"Specialization : "<< hospital->patients[i].assigned_doctor.specialization<<endl;
    }
}

void discharge_patient(Hospital *hospital)
{
	if(hospital->num_of_patients==0)
	{
		cout<<endl<<" No Patient Found! "<<endl;
		return;
	}
	
	cout<<"\n Enter the Discharged Patient Name : ";
	string discharged_patient_name;
	cin>>discharged_patient_name;
	
	
	for(int i=0; i<hospital->num_of_patients;i++)
	{
		if(hospital->patients[i].name==discharged_patient_name)
		{
			hospital->patients[i].name="DISCHARGED";
			cout<<" Patient  Discharged! "<<endl;
			return;
		}
		
	}
		cout<<endl<<" Patient not Found! "<<endl;
}

int main()
{
	Hospital hospital;
	
	cout<<endl<<" Enter the Hospital Name : ";
	cin>>hospital.name;
	cout<<endl<<" Enter the Location of the Hospital : ";
	cin>>hospital.location;
	cout<<endl<<" Enter the Capacity of the Hospital : ";
	cin>>hospital.capacity;

	hospital.num_of_patients=0;
	
	hospital.patients= new Patient[hospital.capacity];
	
    int choice;
    
    do {
        cout<<endl<<"----------------------------------------------------------- Hospital Management System--------------------------------------\n";
        cout<<" 1. Admit Patient "<<endl;
        cout<<" 2. Display Patients "<<endl;
        cout<<" 3. Discharge Patient "<<endl;
        cout<<" 4. Exit "<<endl;
        cout<<endl<<" Enter your choice: ";
        cin>>choice;

        switch(choice) 
		{
        case 1:
		    admit_patient(&hospital);
		break;
        case 2:
		    display_patients(&hospital);
		break;
        case 3:
		    discharge_patient(&hospital);
		break;
        case 4:
		    cout<<endl<<" Exiting ! "<<endl;
		break;
        default: 
		    cout<<endl<<" You Enter Invalid choice! "<<endl;
        
        }
        
    }while(choice != 4);

    delete[] hospital.patients; 
    
    return 0;	
}