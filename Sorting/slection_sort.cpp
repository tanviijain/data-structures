#include<iostream>
using namespace std;
void selectionsort(int a[],int n)
{
    int i,j,k,temp,m;
    for(i=0;i<n;i++)
    {
        m=a[i];
        for(j=i;j<n;j++)
        {
            if(m>=a[j])
            {
                m=a[j];
                k=j;
            }
        }
        temp=a[i];
        a[i]=m;
        a[k]=temp;
    }
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    int i,j,m,temp,a[20],n,k;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    selectionsort(a,n);

}
