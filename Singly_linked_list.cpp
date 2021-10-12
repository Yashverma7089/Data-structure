//program of data structure showing how to create a link list and performing different operations on link list

#include<iostream>
#include<malloc.h>

using namespace std;

struct node
{
	int info;
	struct node *link;
};

int main()
{
	int ch,n,i,data,a;
	struct node *start,*last,*ptr,*mid,*new1,*ptr1;
	
	cout<<"Representation of Linked list\n";
	cout<<"By Yash Verma\n\n";
	cout<<"Enter the number of nodes you want to insert: ";
	cin>>n;
	
	if(n == NULL)
    {
    	cout<<"There is no element in the list\n";
	}
	else {
		//creating link list 
		start = (struct node*)malloc(sizeof(struct node));
		cout<<"Enter info in the first node: ";
		cin>>start->info;
		start->link= NULL;
		ptr = start;
		
		for(i=1 ; i<n ; i++)
		{
			last = (struct node*)malloc(sizeof(struct node));
			cout<<"Enter info int the next node: ";
			cin>>last->info;
			last->link=NULL;
			ptr->link=last;
			ptr=last;
		}
		ptr= start;
		}
		
		do 
		{   //menu of the operation which can be performed by the user on link list
			cout<<"\n\n";
			cout<<"1. Insertion at the beginning\n";
			cout<<"2. Insertion at the end\n";
			cout<<"3. Insertion at after given position\n";
			cout<<"4. Deletion  at the beginning\n";
			cout<<"5. Deletiopn at the end\n";
			cout<<"6. Deletion after the given location\n";
			cout<<"7. Traversing\n";
			
			cout<<"\nEnter your choice: ";
			cin>>ch;
			
			switch(ch)
			{	//Insertion at the beginning of link list
			    case 1: 
					cout<<"\nInsertion at the beginning\n";
					ptr=(struct node*)malloc(sizeof(struct node));
					cout<<"Enter the info in new node: ";
					cin>>ptr->info;
					ptr->link=start;
					start=ptr;
					break;
				
				//Insertion at the end of link list	
				case 2:
					cout<<"\nInsertion at the end\n";
					new1=(struct node*)malloc(sizeof(struct node));
					cout<<"Enter the info in new node: ";
					cin>>new1->info;
					ptr=start;
					
					while(ptr->link!=NULL)
					{
						ptr=ptr->link;
					}
					ptr->link=new1;
					new1->link=NULL;
					break;
					
				//Insertion after the given location in link list
				case 3:
					cout<<"\nInsertion after the given location\n";
					mid=(struct node*)malloc(sizeof(struct node));
					cout<<"Enter the info in new node: ";
					cin>>mid->info;
					cout<<"Enter the data after which u want to insert the node: ";
					cin>>data;
					ptr=start;
					while(ptr->info!=data)
					{
						ptr=ptr->link;
					}
					mid->link=ptr->link;
				    ptr->link=mid;
				    break;
				
				//Deletion at the beginning of the link list
				case 4:
					cout<<"\nDeletion at the beginning is done\n";
					ptr=(struct node*)malloc(sizeof(struct node));
					ptr = start;
					start=ptr->link;
					ptr->link=NULL;
					cout<<"\n Deletion at the beginning is done\n";
					break;
				
				//Deletion at the end of the link list	
				case 5: 
				    cout<<"\nDeletion at the end\n";
				    ptr=(struct node*)malloc(sizeof(struct node));
				    ptr=start;
				    if(ptr->link==NULL)
				    {
				    	cout<<"There is no element given list is empty\n";
					}
					else 
					{
						while(ptr->link!=last)
						{
							ptr=ptr->link;
						}
						ptr->link=last->link;
						last=ptr;
						cout<<"\nDeletion at the end is done\n";
				    }
				    break;
				
				//Deletion after the given location in the link list 
				case 6:
					cout<<"\nDeletion after the given location\n";
					ptr=(struct node*)malloc(sizeof(struct node));
					ptr1=(struct node*)malloc(sizeof(struct node));
					cout<<"Enter the data after which u want to delete node: ";
                    cin>>data;
					ptr=start;
					ptr1=ptr->link;
					while(ptr->info!=data)
					{
						ptr=ptr->link;
						ptr1=ptr1->link;
					}				
					ptr->link=ptr1->link;
					ptr1->link=NULL;
					break;	
				
				//Traversing of the elements in the link list   
				case 7:
					cout<<"\nTraversing\n";
					ptr=(struct node*)malloc(sizeof(struct node));
					cout<<"Data in linked list is: \n";
					ptr=start;
					while(ptr!=NULL)
					{
						cout<<ptr->info<<"\t";
						ptr=ptr->link;
					}
					break;
					
				default :
					cout<<"\nWrong choice\n";
					
			}
			cout<<"\nDo you want to continue press(1/0): ";
			cin>>a;
		}
		while(a==1);
		return 0;
}
