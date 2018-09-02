#include<iostream>
using namespace std;
class stack
{
	struct node
	{
		int data;
		node *next;
	};
	node *new_node;
	node *top;
	public:
		stack()
		{
			top=NULL;
		}
	void push(int item)
	{
		new_node=new node;
		new_node->data=item;
		new_node->next=top;
		top=new_node;
		
	}
	void pop()
	{
		if(top==NULL)
		{
			cout<<"uderflow";
		}
		else
		top=top->next;
	}
	void peek()
	{
		if(top==NULL)
		{
			cout<<"stack is empty";
		}
		else
		{
			cout<<"top element is "<<top->data<<endl;
		}
	}
	void display()
	{
		{
		if(top==NULL)
		{
			cout<<"stack is empty"<<endl;
		}
		else
		{
			while(top!=NULL)
			{
			cout<<"elements are "<<top->data<<endl;
			top=top->next;
		}
	}
	}
	}
};
int main()
{
	int ch,val;
	stack obj;
	cout<<"enter 1 for insert, 2 for delete, 3 for top element ,4 for display and 0 for exit"<<endl;
	cin>>ch;
	while(ch!=0)
	{
		switch(ch)
		{
		case 1:
			cout<<"enter value "<<endl;
			cin>>val;
			obj.push(val);
			break;
			case 2:
				obj.pop();
				break;
				case 3:
					obj.peek();
					break;
					case 4:
						obj.display();
						break;
						default:
							cout<<"wrong input";
							break;
						}
							cout<<"enter 1 for insert, 2 for delete, 3 for top element ,4 for display and 0 for exit"<<endl;
	                        cin>>ch;
	}
}
