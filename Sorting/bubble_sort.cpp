#include<iostream>
using namespace std;
int main()
{
int n,na;
cout<<"Enter the number of arrays: ";
cin>>na;
int i,j,temp;
for(int k=0;k<na;k++)
{
int a[20],n;
cout<<"\nEnter size of "<<k+1<<" array: ";
cin>>n;
for(i=0;i<n;i++)
{
cin>>a[i];
}
for(i=0;i<n;i++)
{
cout<<a[i]<<" ";
}
for(i=0;i<n-1;i++)
{
    for(j=0;j<n;j++)
    {
        if(a[j]>a[j+1])
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
}
cout<<"\nAfter sorting: \n";
for(i=0;i<n;i++)
{
cout<<a[i]<<" ";
}
}
}
