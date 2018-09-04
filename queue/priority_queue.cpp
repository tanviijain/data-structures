#include<iostream>
using namespace std;
	struct node
	{
		int data,pri;
		struct node *next;
	}*start;
	struct node *  create_node(int val, int pr)
 {
 	struct node *temp;
 	temp=new node;
 	temp->data=val;
 	temp->pri=pr;
 	temp->next=NULL;
 	return temp;
 }
	void insert()
	{
			struct node *ptr,*p;
	int val,pr;
	cout<<"enter a number to be inserted ";
 	cin>>val;
	 cout<<" enter its priority ";
	 cin>>pr;
			ptr=create_node(val,pr);
		if(start==NULL|| pr<start->pri)
		{
		ptr->next=start;
		start=ptr;	
		}
		else
		{
			p=start;
			while(p->next!=NULL && p->pri<pr)
			{
				p=p->next;
			}
			ptr->next=p->next;
			p->next=ptr;
		}
	}
	void display()
{
struct node *temp;
	temp=start;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }       
}
int main()
{
	start=NULL;
	
				insert();
				insert();
				insert();
				display();
			
}
