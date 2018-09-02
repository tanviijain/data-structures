#include<iostream>
using namespace std;
class s1
{
char a[50];
int top;
public:
	s1()
	{
		top=-1;
	}
	void push(char num)
	{
	a[++top]=num;	
	}
	char pop()
	{
		return(a[top--]);
	}
	void fctn(char a[50])
	{
	char *e,x;
	e=a;
	int count=1;
	while(*e!='\0')
	{
		if(*e=='('||*e=='['||*e=='{')
		{
			push(*e);
		}
		else if(*e==')')
		{
			if((x=pop())=='(')
			{
				count=2;
			}
			else
			{
				count=1;
			}
		}
		else if(*e=='}')
		{
			if((x=pop())=='{')
			{
				count=2;
			}
			else
			{
				count=1;
			}
		}
		else if(*e==']')
		{
			if((x=pop())=='[')
			{
				count=2;
			}
			else
			{
				count=1;
			}
		}
		e++;
	}
	if(count%2==0 && top==-1)
	{
		cout<<"equation is valid";
		}	
		else
		{
			cout<<"invalid";
		}
	}
	
};
int main()
{
	char a[50];
	s1 obj;
	cin>>a;
	obj.fctn(a);
}
