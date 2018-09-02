#include<iostream>
using namespace std;
class stack
{
	int *arr,s,top;
	public:
		stack(int n)
		{
		s=n;
		top=-1;
			arr=new int[s];
		}
		void push(int item)
		{
			if(top==s-1)
			{
				cout<<"overflow";
			}
			else
			{
				top++;
				arr[top]=item;
			}
		}
		void pop()
		{
			if(top==-1)
			{
				cout<<"underflow";
			}
			else
			top--;
		}
		void display()
		{
			for(int i=0;i<=top;i++)
			{
				
				cout<<arr[i];
			}
		}
};
int main()
{
	int s,ch,val;
	cout<<"enter size of array ";
	cin>>s;
	stack obj(s);
	cout<<"enter choice 1 for insert ,2 for delete and 0 for exit ";
	cin>>ch;
	while(ch!=0)
	{
		switch(ch)
		{
			case 1:
				cout<<"enter value to be inserted";
				cin>>val;
				obj.push(val);
				break;
				case 2:
					obj.pop();
					break;
					default:
						cout<<"wrong input";
				
		}
		cout<<"enter choice 1 for insert ,2 for delete and 0 for exit ";
	cin>>ch;
	}
	obj.display();
}
