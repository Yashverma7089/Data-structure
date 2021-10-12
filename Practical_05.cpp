//	Write a menu driven program to implement following operations on the singly linked list.
//	(a)Insert a node at the front of the linked list.
//	(b)Insert a node at the end of the linked list.
//	(c)Insert a node such that linked list is in ascending order.

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
			cout<<"1. Insert a node at the front of the linked list\n";
			cout<<"2. Insert a node at the end of the linked list\n";
			cout<<"3. Insert a node such that linked list is in ascending order\n";
			cout<<"4. Traversing\n";
			
			cout<<"\nEnter your choice: ";
			cin>>ch;
			
			switch(ch)
			{	//Insertion at the beginning of link list
			    case 1: 
					cout<<"\nInsert a node at the front of the linked list\n";
					ptr=(struct node*)malloc(sizeof(struct node));
					cout<<"Enter the info in new node: ";
					cin>>ptr->info;
					ptr->link=start;
					start=ptr;
					break;
				
				//Insertion at the end of link list	
				case 2:
					cout<<"\nInsert a node at the end of the linked list\n";
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
					cout<<"\nInsert a node such that linked list is in ascending order\n";
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
				
				//Traversing of the elements in the link list   
				case 4:
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
