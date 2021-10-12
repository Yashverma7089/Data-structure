//	Write a menu driven program to implement following operations on the singly linked list.
//	(a)Delete a first node of the linked list.
//	(b)Delete a node at the last location.
//	(c)Delete a node after specified position.

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
			cout<<"1. Delete a first node of the linked list\n";
			cout<<"2. Delete a node before specified position\n";
			cout<<"3. Delete a node after specified position\n";
			cout<<"4. Traversing\n";
			
			cout<<"\nEnter your choice: ";
			cin>>ch;
			
			switch(ch)
			{	//Deletion at the beginning of the link list
				case 1:
					cout<<"\nDelete a first node of the linked list\n";
					ptr=(struct node*)malloc(sizeof(struct node));
					ptr = start;
					start=ptr->link;
					ptr->link=NULL;
					break;
				
				//Deletion at the end of the link list	
				case 2: 
				    cout<<"\nDelete a node at the last location\n";
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
					}
				    break;
				
				//Deletion after the given location in the link list 
				case 3:
					cout<<"\nDelete a node after specified position\n";
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
