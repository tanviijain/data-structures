#include<iostream> 
using namespace std;
class queue
{
	
	public:
		int *a;
		int x;
	int front,rear;
		queue(int b)
		{
			front=-1;
			rear=-1;
		x=b;
		a=new int[x];	
		}
		void insert(int item)
		{
			if(front==-1&&rear==-1)
			{
				front++;
				rear++;
				a[rear]=item;
				
			}
			else if(rear==x-1)
			{
				cout<<"overflow";
			}
			else
			{
				rear++;
				a[rear]=item;
			}
		}
		void del()
		{
			if(front==-1&&rear==-1)
			{
				cout<<"queue is empty";
			}
			else if(front==rear)
			{
				front=-1;
				rear=-1;
			}
			else
			{
				front++;
			}
		}
		void display()
		{
			for(int i=front;i<=rear;i++)
			{
				cout<<a[i];
			}
		}
};
int main()
{
	int s,ch,item;
	cout<<"enter size ";
	cin>>s;
	queue obj(s);
	cout<<"enter 1 for insert,2 for delete, 3 for display and 0 for exit ";
	cin>>ch;
	while(ch!=0)
	{
	switch(ch)
	{
		case 1:
			cout<<"enter element ";
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
						cout<<"wrong input";
	}
cout<<"enter 1 for insert,2 for delete, 3 for display and 0 for exit ";
	cin>>ch;
	}
}

