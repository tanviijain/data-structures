#include<iostream>
using namespace std;
class s1
{
	public:
		int top;
		char a[50];
	s1()
	{
		top=-1;
	}
		void push(char num)
	{
		a[++
		top]=num;
	}
	int pop()
	{
		return(a[top--]);
	}
fctn(char a[50])
{
	char *e;
	int num;
	e=a;
	while(*e!='\0')
	{
		if(isalnum(*e))
		{
			num=*e-48;
			push(num);
		}
		else
		{
			int a=pop();
			int b=pop();
			int c;
			switch(*e)
			{
				case '+':
					c=a+b;
					push(c);
					break;
					case '-':
					c=a-b;
					push(c);
					break;
					case '*':
					c=a*b;
					push(c);
					break;
					case '/':
					c=a/b;
					push(c);
					break;
					case '^':
					c=a^b;
					push(c);
					break;
			}
		}
		e++;
	}
	while(top!=-1)
	{
		cout<<pop();
	}
	}	
};
int main()
{
	s1 obj;
	char a[50];
	cout<<"enter postfix ";
	cin>>a;
	obj.fctn(a);
}
