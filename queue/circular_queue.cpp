#include<iostream>
using namespace std;
class queue
{
int *arr,x;
int front,rear;	
public:
queue(int s)
{
	x=s;
	front =-1;
	rear=-1;
	arr=new int[x];
	}
	void insert(int item)
	{
		if(front==-1 && rear==-1)
		{
			front++;
			rear++;
			arr[rear]=item;
		}
		else if(front==0 && rear==x-1|| rear==front-1)
		{
			cout<<"overflow "<<endl;
		}
		else
		{
			if(rear==x-1)
			rear=0;
			else
			{
				rear++;
				arr[rear]=item;
			}
		}
		}
		void del()
		{
		
				if(front==-1 && rear==-1)
				{
					cout<<"underflow "<<endl;
				}
				else if(front==rear)
				{
					front=-1;
					rear=-1;
				}
				else if(front=x-1)
				{
					front=0;
				}
				else
				{
					front++;
				}
				}
				void display()
				{
					if(front==-1)
					{
						cout<<"queue is empty ";
					}
					else if(rear<front)
					{
						for(int i=front;i<+x;i++)
						{
							cout<<arr[i];
						}
						for(int i=0;i<=rear;i++)
						{
							cout<<arr[i];
						}
					}
					else
					{
						for(int i=front;i<=rear;i++)
						{
							cout<<arr[i];
						}
					}
					}	
};
int main()
{
	int s,item;
	cout<<" enter size ";
	cin>>s;
	queue obj(s);
	int ch;
	cout<<"enter 1 for insert, 2 for delete, 3 for display and 0 for exit ";
	cin>>ch;
	while(ch!=0)
	{
		switch(ch)
		{
			case 1:
				cout<<" enter value ";
				cin>>item;
			  obj.insert(item);
			  break;
			  case 2:
			  	obj.del();
			  	break;
			  	case 3:
			  		obj.display();
			  		break;
			  	default:
			  		cout<<"wrong input ";
			  		break;
				
		}
		cout<<"enter 1 for insert, 2 for delete, 3 for display and 0 for exit ";
	cin>>ch;
	}
}
