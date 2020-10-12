#include<iostream>
#include<stdlib.h>
using namespace std;

//-------------------------------------------Class Add---------------------------------------
class add
{  
    protected:
		char first[20],last[20],sec[3];
		float m[5], total;
	public:
		int roll,j;
	public:
		void get()
		{
				cout<<"Enter first name : ";
				cin>>first;
				cout<<"Enter last name : ";
				cin>>last;
				cout<<"Enter Roll no : ";
				cin>>roll;
				cout<<"Enter section : ";
				cin>>sec;		
				
				total=0;
				for(j=0;j<5;j++)
				m[j]=0;	
		}		
		
		void show()
		{
			cout<<endl<<"\nFirst Name : "<<first;
			cout<<"\nLast Name : "<<last;
			cout<<"\nRoll Number : "<<roll;
			cout<<"\nSection : "<<sec<<endl;
		}
		
};
//-----------Class Modify inherited with class Add---------------

class modify : public add
{
	
	
	public:
		
		void modf()
		{
			cout<<"Enter new first name:";
			cin>>first;
		}
		
		void modl()
		{
			cout<<"Enter new Last name : ";
			cin>>last;
		}
		
		void modr()
		{
			cout<<"Enter new roll number:";
			cin>>roll;
		}
		
		void mods()
		{
			cout<<"Enter new section : ";
			cin>>sec;
		}
		
			
			
		void score()
		{		
					
			cout<<"Enter marks of 5 subjects: ";
					for(j=0;j<5;j++)
					{
						cout<<"\nSubject "<<j+1<<" : ";
						cin>>m[j];
					}
		}
		
		void marks()
		{
	
			
			for(j=0;j<5;j++)
			total = total + m[j];	

			if(total!=0)	//------------------Exception handling if total value is zero-----------------
			{
				cout<<"The marks of 5 subjects are:\n";
				for(j=0;j<5;j++)
				{
					cout<<"Subject "<<j+1<<" : "<<m[j]<<endl;
				}
				cout<<"\nTotal score: "<<total<<endl;
			}
			else
			{
				throw (total);
			}
			
		}
};

//--------------------------------------------------Main Block------------------------------------------------
int main()
{
	int c,size = 0,i=0,v;
	int check;	
	modify *p;
	p = (modify*) calloc(size, sizeof(modify));		//---------Dynamically allocated memory for objects----------
	
	cout<<"\n\t\t\t  STUDENT DATABASE MANAGEMENT";
	cout<<"\n\n1. Add Records\n2. List Records\n3. Modify Records\n4. Enter Marks\n5. Display Marks\n6. Exit Program ";
	while(1)
	{	
 		cout<<"\n\nEnter your choice:";
		cin>>c;
	
		switch(c)
		{
			//-----------Adding Records------------
			case 1 :size++;		
					p = (modify*)realloc(p, size*sizeof(modify));
					(p+i)->get();
					i++;
					break;
					
					//--------------Displaying Records--------------
			case 2 :for(i=0;i<size;i++)		
					{
						(p+i)->show();		
					}
					break;
					
						//----------Modifying Records-----------
			case 3: cout<<"Enter Roll number of the student whose record has to be edited : ";	
					cin>>check;
					for(i=0;i<size;i++)
					{
						if(check == (p+i)->roll)
						{
							cout<<"\n\nRecord Found\n\n";
							cout<<"1.First Name\n2.Last Name\n3.Roll number\n4.Section";
							cout<<"\n\nModify: Enter your choice: ";
							cin>>v;
							if(v==1)
							{
								(p+i)->modf();
								break;
							}
							else if(v==2)
							{
								(p+i)->modl();
								break;
							}
							else if(v==3)
							{
								(p+i)->modr();
								break;							
							}
							else if(v==4)
							{
								(p+i)->mods();
								break;
							}
						
						}
						else
						{
							cout<<"Record not found";
							break;
						}
					}					
					break;
					
					//-----------Input Marks of a student------------
			case 4: cout<<"Enter Roll number of the student whose marks has to be entered : ";		
					cin>>check;
					for(i=0;i<size;i++)
					{
						if(check == (p+i)->roll)
						{
							cout<<"\n\nRecord Found\n\n";
							(p+i)->score();
							break;
						}
						else
						{
							cout<<"Record not found";
						}
					}
					break;
					
			//----------- Displaying Marks and total of a student---------
			case 5: cout<<"Enter Roll number of the student whose marks has to be listed : ";		
					cin>>check;
					for(i=0;i<size;i++)
					{
						if(check == (p+i)->roll)
						{
							try
							{
								(p+i)->marks();
								break;
							}
							
							//---------------Catching Exception------------
							catch(float i)
							{
								cout<<"\nException Caught: No Record of Marks found !";
								cout<<"\nPlease input marks";
							}
						}
						else
						{
							cout<<"Record not found";
							break;
						}
					}	
					break;
			
			case 6: exit(0);
					break;
		
			default: cout<<"\nChoose correct option\n";
		}
	}
}
