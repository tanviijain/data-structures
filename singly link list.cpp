#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{
	int data;
	node *next;
}*start;
 struct node *create_node(int val)
 {
 	struct node *temp;
 	temp=new(struct node);
 	temp->data=val;
 	temp->next=NULL;
 	return temp;
 }
 void insert_beg()
 {
 	struct node *p;
 	int val;
 	cin>>val;
 	p=create_node(val);
 	if(start==NULL)
 	{
 		start=p;
 		p->next=NULL;
	 }
	 else
	 {
	 	p->next=start;
	 	start=p;
	 	
	 }
 }
 void insert_last()
 {
 	struct node *temp,*p ;
 	int val;
 	cout<<"enter a number to insert it at last ";
 	cin>>val;
 	p=create_node(val);
 	temp=start;
 	while(temp->next!=NULL)
 	{
 		temp=temp->next;
 	}
 		p->next=NULL;
 			temp->next=p;
 }
 void insert_after()
 {
 	struct node *p,*temp;
 	int val,num;
 	cout<<"enter a number after which you want to insert ";
 	cin>>num;
 	cout<<"enter a number to be inserted ";
 	cin>>val;
 	p=create_node(val);
 	temp=start;
 	while(temp->data!=num && temp->next!=NULL)
 	{
 		temp=temp->next;
	 }
	 if(temp!=NULL)
	 {
	 	if(temp->next==NULL)
	 	{
	 		temp->next=p;
	 		p->next=NULL;
		 }
		 else
		 {
		 	p->next=temp->next;
		 	temp->next=p;
		 }
	 }
 }
 void insert_before()
 {
 	struct node *p,*temp,*ptr;
 	int num,val;
 	cout<<"enter a number before which you want to insert ";
 	cin>>num;
 	cout<<"enter a number to be inserted ";
 	cin>>val;
 	p=create_node(val);
 	temp=start;
 	while(temp->data!=num && temp->next!=NULL)
 	{
 		ptr=temp;
 		temp=temp->next;
	 }
	 if(temp!=NULL)
	 {
	 	if(temp==start)
	 	{
	 		p->next=start;
	 			start=p;
		 }
		 else
		 {
		 	ptr->next=p;
		 	p->next=temp;
		 	
		 }
	 }
 }
 
void delete_beg()
{
	struct node *temp,*ptr;
	temp=start;
	if(start=NULL)
	{
		cout<<"there is no list ";
	}
	else
	{
		if(temp->next==NULL)
		{
			ptr=temp;
			start=NULL;
			free(ptr);
		}
		else
		{
		ptr=temp;
		start=temp->next;
		free(temp);
	}
}
}
void delete_last()

{
	struct node *temp,*ptr;
	temp=start;
	while(temp->next!=NULL)
	{
		ptr=temp;
		temp=temp->next;
	}
	ptr->next=NULL;
	free(temp);
	
}
void delete_given_node()
{
	struct node *temp,*ptr;
	int num;
	cout<<"enter a element to be delected ";
	cin>>num;
	temp=start;
	while(temp->data!=num && temp!=NULL)
	{
		ptr=temp;
		temp=temp->next;
	}
	if(temp==start)
	{
		start=temp->next;
		free(temp);
	}
	else if(temp->next==NULL)
	{
		ptr->next=NULL;
		free(temp);
	}
	else
	{
	ptr->next=temp->next;
	free(temp);
}
}
void delete_before()
{
	struct node *temp,*ptr,*preptr;
	int num;
	cout<<"enter a number before which u want to delete ";
	cin>>num;
	if(start!=NULL)
	{
		temp=start;
		while(temp->data!=num && temp!=NULL)
		{
			preptr=ptr;
			ptr=temp;
			temp=temp->next;
		}
		if(temp!=NULL)
		{
			if(temp==start)
			{
				cout<<"node cannot be delected as it is first node"<<endl;
			}
			else if(temp==start->next)
			{
				start=temp;
				free(ptr);
			}
			else
			{
				preptr->next=temp;
				free(ptr);
			}
		}
		else
		{
			cout<<"number is not there in list"<<endl;
		}
	}
	else
	{
		cout<<"there is no list";
	}
	
}
void delete_after()
{
	struct node *temp,*ptr,*ptr1;
	int num;
	cout<<"enter a number after which u want to delete ";
	cin>>num;
	if(start!=NULL)
	{
    temp=start;
	while(temp->data!=num )
	{
		temp=temp->next;
		}	
		if(temp!=NULL)
		{
			if(temp->next==NULL)
			{
				cout<<"number cannot be celeted as it last number"<<endl;
			}
			else if ((temp->next->next)==NULL)
			{
				ptr=temp->next;
				temp->next=NULL;
				free(ptr);
			}
			else
			{
				ptr=temp->next;
				ptr1=temp->next->next;
				temp->next=ptr1;
				free(ptr);
			}
		}
		else
		
		{
			cout<<"number is not present in list"<<endl;
		}
	}
	else
	{
		cout<<"there is no list"<<endl;
	}
}
 void show()
 {
 	struct node *temp;
 	temp=start;
 	while(temp!=NULL)
 	{
 		cout<<temp->data<<endl;
 		temp=temp->next;
	 }
 }
 int main()
 {
 	start=NULL;
 	for(int i=0;i<5;i++)
 	{
 	cout<<"enter a number ";
 	insert_beg();
  }
 	cout<<"insertion at beg"<<endl;
 	show();
 	insert_last();
 	cout<<"insertion at last"<<endl;
 	show();
 	insert_after();
 	cout<<"insertion after a number"<<endl;
 	show();
 	insert_before();
 	cout<<"insertion before a number"<<endl;
 	show();
 	delete_beg();
 	cout<<"after delecting element from beg "<<endl;
 	show();
 	delete_last();
 	cout<<"after delecting element from last "<<endl;
 	show();
 	delete_given_node();
 	cout<<"after delecting given node "<<endl;
 	show();
 	delete_before();
 	cout<<"delecting before node"<<endl;
 	show();
 	delete_after();
 	cout<<"delecting after node "<<endl;
 	show();
 }
