using namespace std;
#include<iostream>
class array1
{
int *arr,n;
public:
array1 (int size_)
{
n=size_;
arr=new int[n];
}
void input()
{
for (int i=0;i<n;i++)
{
cin>>arr[i];
}
}
void display()
{
for (int i=0;i<n;i++)
{
cout<<arr[i]<<endl;
}
}
void insert1(int pos,int item);

 void delete1(int loc);

void search1(int value);

};
void array1::insert1(int pos,int item)
{
    pos=pos-1;
for (int i=n-1;i>=pos;i++)
{
arr[i+1]=arr[i];
}
arr[pos]=item;
n=n+1;
}
void array1::delete1(int loc)
{
for (int i=loc;i<n;i++)
{
arr[i-1]=arr[i];
}
n=n-1;
}
void array1:: search1(int value)
{
int flag=0;
for (int i=0;i<n;i++)
{
if (arr[i]==value)
{
flag=1;
cout<<"FOUND";
break;
}
}
if (flag==0)
{
cout<<"NOT FOUND";
}
}
int main()
{
int size_,ch;
cout<<"enter size of array"<<endl;
cin>>size_;
array1 ob(size_);
cout<<"enter 1 for entering values,2 for insertion,3 for deletion,4 for searching,5 to display,0 to exit"<<endl;
cin>>ch;
while (ch!=0)
{
switch(ch)
{
case 1:
ob.input();
break;

case 2:
int item,loc;
cout<<"enter value to be entered";
cin>>item;
cout<<"enter position where value is to be entered"<<endl;
cin>>loc;
ob.insert1(loc,item) ;
ob.display();
break;
case 3:
    int loc1;
cout<<"enter location from where item has to be deleted"<<endl;
cin>>loc1;
ob.delete1(loc1);
ob.display();
break;
case 4:
int item1;
cout<<"enter item to be searched"<<endl;
cin>>item1;
ob.search1(item1);
break;
case 5:
    ob.display() ;
  break;
}
cout<<"enter 1 for entering values,2 for insertion,3 for deletion,4 for searching,5 to display,0 to exit"<<endl;
cin>>ch;

}
}
