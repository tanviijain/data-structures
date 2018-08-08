#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
   int data;
   struct node *prev;
   struct node *next;
}*start;

struct node * create_node(int val)
{
    struct node *temp;
    temp= new(struct node);
    temp->data=val;
    temp->prev=NULL;
    temp->next=NULL;
    return temp;
};

void insert_beg()
{
    int val;
    cout<<"enter a value for node ";
    cin>>val;
    struct node*p;
    p=create_node(val);

    if(start==NULL)
    {
        start=p;
        p->next=NULL;
        p->prev=NULL;

    }
    else
    {
        p->next=start;
        start->prev=p;
        start=p;
        p->prev=NULL;
    }
}
void insert_last()
{
    int val;
    cout<<"enter a number to insert at last ";
    cin>>val;
    struct node *p, *temp;
    p=create_node(val);
    temp=start;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    p->next=NULL;
    p->prev=temp;
    temp->next=p;


}
void insert_after()
{
    int num,val;
    cout<<"enter a number after which you want to enter your value ";
    cin>>num;
    cout<<"enter value ";
    cin>>val;
    struct node *p,*temp;
    p=create_node(val);
    temp=start;
    while(temp->data!=num && temp!=NULL)
    {
        temp=temp->next;
    }
    if(temp!=NULL)
    {
    	if(temp->next==NULL)
    	{
    		 p->prev=temp;
        p->next=temp->next;
        temp->next=p;
		}
		else
		{
		
        p->prev=temp;
        p->next=temp->next;
        temp->next=p;
        temp->next->prev=p;
    }
    }
    else
    {
        cout<<"not there";
    }
}
void insert_before()
{
    int num,val;
     cout<<"enter a number before which you want to enter your value ";
    cin>>num;
    cout<<"enter value ";
    cin>>val;
    struct node *p,*temp;
    p=create_node(val);
    temp=start;
    while(temp->data!=num && temp!=NULL)
    {
        temp=temp->next;
    }
    if(temp!=NULL)
    {
    	if(temp==start)
    	{
    	p->next=start;
        start=p;
        p->prev=NULL;
    		
		}
		else
		{
			temp->prev->next=p;
	     p->next=temp;
        p->prev=temp->prev;
        temp->prev=p;
        }
    }
    else
    {
        cout<<"not there";
    }
}
void delete_entire_list()

{
	struct node *temp,*ptr;
	if(start!=NULL)
	{
		temp=start;
		while(temp!=NULL)
		{
			ptr=temp;
			temp=temp->next;
			temp->prev=NULL;
			free(ptr);
		}
	}
	start=NULL;
}
void show()
{
    struct node *temp;
    temp=start;
    while(temp!=NULL)
    {
    
		cout<<temp->data;
        temp=temp->next;
    }
}
void delete_beg()
{
	struct node *ptr;
	if(start==NULL)
	{
		cout<<"there is no list";
	}
	else
	{
		if(start->next==NULL)
		{
			ptr=start;
			start=NULL;
			free(ptr);
		}
		else
		{
			ptr=start;
			start=ptr->next;
			start->prev=NULL;
			free(ptr);
		}
	}
}
void delete_last()
{
	struct node *temp,*ptr;
	temp=start;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->prev->next=NULL;
	ptr=temp;
	free(temp);
}
void delete_given_node()
{
	int num;
	struct node *temp,*ptr;
	cout<<"enter a number to be deleted ";
	cin>>num;
	temp=start;
	while(temp->data!=num && temp!=NULL)
	{
		temp=temp->next;
	}
	if(temp==start)
	{
		ptr=temp;
		start=temp->next;
		temp->next->prev=NULL;
		free(ptr);
		
	}
	else if(temp->next==NULL)
	{
		ptr=temp;
	temp->prev->next=NULL;	
	free(ptr);
	}
	else
	{
		ptr=temp;
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		free(temp);

	}
}
int main()
{
    start=NULL;
    insert_beg();
    insert_beg();
    insert_beg();
    insert_beg();
    cout<<" After insertion at beg ";
    show();
    cout<<endl;
    insert_last();
    cout<<" After insertion at last ";
    show();
    cout<<endl;
    insert_after();
    cout<<" After insertion after your num ";
    show();
    cout<<endl;
    insert_before();
    cout<<" After insertion before your num ";
    show();
    cout<<endl;
    delete_beg();
    cout<<" After deleting a number from beg ";
    show();
    cout<<endl;
    delete_last();
    cout<<" After deleting a number at last ";
    show();
    cout<<endl;
    delete_given_node();
    cout<<"after delecting a given node ";
    show();
    delete_entire_list();
    show();

}
