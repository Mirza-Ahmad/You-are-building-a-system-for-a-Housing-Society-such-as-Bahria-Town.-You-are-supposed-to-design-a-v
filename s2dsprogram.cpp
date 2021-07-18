#include<iostream>
using namespace std;
class FOR_HOUSE
{
  public:
  int info;
   FOR_HOUSE * next;
    FOR_HOUSE(int house_info)
     {
      info=house_info;
       next= NULL;	
      }	
      void display()
       {
        cout<<"\t\t\t \t\tHouse: "<<info<<endl;
        }
};
class FOR_STREET
{
public:	
int stre_info;
 FOR_HOUSE * head_house;
  int n;
   int house_no=1;
     FOR_STREET * next;
       FOR_STREET(int street_info)
       {
        stre_info=street_info;
        next=NULL;
       }
        void display()
        {
   	    cout<<"\t\t\t Street"<<stre_info<<endl;
   	      for(FOR_HOUSE* temp = head_house; temp != NULL ; temp = temp->next )
           temp->display();
           cout<<endl;
          }
        void set_House()
        {
   	     FOR_HOUSE * temp;
         head_house=NULL;
         cout<<"How many houses does 'Street "<< stre_info <<"' have? ";
          cin>>n;
           for(int i=0; i<n; i++)
            {
            if(!head_house)
             {
              temp=new FOR_HOUSE(house_no++);
              head_house=temp;
	         }
	          else
	          {
	           temp->next=new FOR_HOUSE(house_no++);
	           temp=temp->next;
	           }
	         }
         } 
};
class FOR_SECTOR
{
 public:
     int street_no=1;
     FOR_STREET * head_street;
     int n;
 	 char e_s;
     FOR_SECTOR * next;
     FOR_SECTOR(char e)
     {
        e_s=e;
        next=NULL;
     }   
	     void display()
	      {
	      	cout<<"\t\t\t SECTOR: "<<e_s<<endl;
	      	 for(FOR_STREET* temp = head_street; temp != NULL ; temp = temp->next )
             temp->display();
             cout<<endl;
		  }
		  void set_Street()
		  {
		   FOR_STREET * temp;	
           head_street=NULL;
           cout<<"How many streets does 'Sector "<< e_s <<"' have? ";
			 cin>>n;		  	
		  	 if(!head_street)
		  	 {
		  	  temp=new FOR_STREET(street_no++);
			  head_street=temp;	
			 }
		  	 else
			 {
			  temp->next=new FOR_STREET(street_no++);
			  temp=temp->next;	
			 }
			temp->set_House(); 
		  }
};
class FOR_BLOCK
{	
public:
  char blo_info;
   FOR_BLOCK * next;
     FOR_SECTOR * head_sector;
      char SECTOR_NAME='A';
       int n;
       FOR_BLOCK(char block_info)
        {
      	blo_info=block_info;
      	next=NULL;
        }
        void display()
        {
        	cout<<"\t\t\t BLOCKS: "<<blo_info<<endl;
        	  for(FOR_SECTOR* temp = head_sector; temp != NULL ; temp = temp->next )
              temp->display();
              cout<<endl;
		}
        void set_SECTOR()
        {
        	FOR_SECTOR * temp;
            head_sector=NULL;
            cout<<"How many sectors does 'Block "<< blo_info <<"' have? ";
        	  cin>>n;
        	   for(int i=0; i<n; i++)
        	    {
        	    	if(!head_sector)
        	    	{
        	    	temp=new FOR_SECTOR(SECTOR_NAME++);
        	    	head_sector=temp;
        	        }
        	        else
        	        {
        	        temp->next=new FOR_SECTOR(SECTOR_NAME++);
        	        temp=temp->next;
					}
					temp->set_Street();
				}
		}
};
class Society
{
public:
 string city_name;
  string society_name;
    int n;
     FOR_BLOCK * head_block;
      char BLOCK_NAME='A';
       void display()
        {
         cout<<"\t\t\tThe city name is "<<city_name<<"\n"<<"\t\t\tThe society name is = "<<society_name<<endl;
	      for(FOR_BLOCK* temp = head_block; temp != NULL ; temp = temp->next )
           temp->display();
           cout<<endl;
      }	
   void set_blocks()
   {
   	FOR_BLOCK * temp;
     head_block=NULL;
     cout<<"Enter the name of the society: ";
      getline(cin,society_name);
   	  cout<<"Enter the name of the city : ";
   	    getline(cin,city_name);
   	          cout<<"How many blocks does this society("<< society_name <<") has? ";
   	           cin>>n;
   	           for(int i=0; i<n; i++)
   	           {
   	              if(head_block==NULL)
   	               {
   	                temp=new FOR_BLOCK(BLOCK_NAME++);
   	                 head_block=temp;
				    }
   	              else
   	              {
   	              	temp->next=new FOR_BLOCK(BLOCK_NAME++);
   	              	temp=temp->next;
				  }
				  temp->set_SECTOR();
                }
   }	
};
int main(void)
{
Society s;
s.set_blocks();
s.display();
return 0;		
}