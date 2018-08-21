using namespace std;
#include<iostream>
#define max 10
char arr[max];
int num=0;

void push(char k){
	num++;
	arr[num]=k;
}

int check(char k){
	
	int flag=0;
	
	if(k==')' && arr[num]=='('){
		num--;
	}
	
	else if(k==']' && arr[num]=='['){
		num--;
	}
	
	else if(k=='}' && arr[num]=='{'){
		num--;
	}
	
	else{
		flag=1;
	}
	
	return flag;
}

void display(){
	
	if(num>0){
		cout<<"This is not a valid query!";
	}
	else{
		cout<<"valid";
	}
	
}

int main(){
int a,che;
char n;

cout<<"Enter the number of elements"<<endl;
cin>>a;

for(int i=0;i<a;i++)
{
cin>>n;

if(n=='[' || n=='{' || n=='(')
{
	push(n);
}

if(n==']' || n=='}' || n==')'){
	che=check(n);
}

if(che==1){
	cout<<"invalid";
	break;
}

}

display();

}

