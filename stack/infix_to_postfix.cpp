#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;
char stack_[50];
char postfix[50];
int top=-1;
int a=0;
int preceed(char ch)
{
	if(ch=='^')
	return 3;
	else if(ch=='*'||ch=='/')
	return 2;
	else if(ch=='+'||ch=='-')
	return 1;
	else
	return 0;

}
void push(char n)
{
	top++;
	stack_[top]=n;
}
void insert_postfix(char s)
{
	postfix[a]=s;
	a++;
}
void pop()
{
if(stack_[top]=='(')
{
	
}	
	else
		insert_postfix(stack_[top]);
		top--;
}
int main()
{
	char infix[100];
	int index;
cout<<"enter infix ";
cin>>infix;
 index=strlen(infix);
infix[index]=')';
infix[index+1]='\0';
int top=0;
stack_[top]='(';
int i=0;
while(infix[i]!='\0')
{
	if(infix[i]=='(')
	{
		push(infix[i]);
	}
	else if(isalpha(infix[i])||isdigit(infix[i]))
	{
		insert_postfix(infix[i]);
	}
	else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^')
	{
		if(preceed(infix[i])>preceed(stack_[top]))
		{
			push(infix[i]);
		}
		else if(preceed(infix[i])<=preceed(stack_[top]))
		{
			while(preceed(infix[i])<=preceed(stack_[top]))
			{
				pop();
			}
			push(infix[i]);
		}
	}
	else if(infix[i]==')')
	{
		while(stack_[top]!='(')
		{
			pop();
		}
		pop();
	}
	i++;
	}
	postfix[a]='\0';
	cout<<postfix;	
}
