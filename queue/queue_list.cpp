#include<iostream>
using namespace std;
class queue
{
	struct node
	{
		int val;
		struct node *next;
	};
		node *front;
		node *rear;
		node *save,*new_node;
		node *ptr,*temp;
		public:
	queue()
	{
		front =NULL;
		rear=NULL;
	}
	void insert()
	{
		int num;
		cout<<"enter number to insert "<<endl;
		cin>>num;
		while(num!=-1)
		{
		if(rear==NULL)
		{
			new_node= new node;
			new_node->val=num;
			new_node->next=NULL;
			rear=new_node;
			front=new_node;
			save=new_node;
			}
		else
		{
			new_node= new node;
			new_node->val=num;
			new_node->next=NULL;
			save->next=new_node;
			save=new_node;
			rear=save;
			}
			cout<<"again enter a no "<<endl;
			cin>>num;	
		}
	}
	void display()
	{
		if(front!=NULL)
		{
	temp=front;
	while(temp->next!=NULL)
	{
	cout<<temp->val<<endl;
	temp=temp->next;	
}
cout<<temp->val;
}
else
{
	cout<<"queue is empty"<<endl;

}

	}
	void del()
	{
	if(front!=NULL)
	{
		ptr=front;
		front=front->next;
		cout<<ptr->val;
		delete(ptr);
		
		}
		else
		{
			cout<<"queue is empty";
			}	
	}
	
};
int main()
{
	int ch;
	queue obj;
	cout<<"enter 1 for insert,2 for delete, 3 for for display and 0 for exit ";
	cin>>ch;
	while(ch!=0)
	{
		switch(ch)
		{
			case 1:
				obj.insert();
				break;
				case 2:
					obj.del();
					break;
					case 3:
						obj.display();
						break;
						default:
							cout<<"wrong input";
							break;
		}
		cout<<"enter 1 for insert,2 for delete, 3 for for display and 0 for exit ";
	cin>>ch;
	}
}
