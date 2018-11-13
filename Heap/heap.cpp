#include<iostream>
using namespace std;
class heap
{
public:
    void create_max_heap(int *,int);
    void create_min_heap(int *,int);
    void max_heapify(int *,int,int);
    void min_heapify(int *,int,int);
    void delete_from_heap(int *,int&);
    void insertion_in_heap(int *,int,int&);
    void display_heap(int *,int);
};
void heap::create_max_heap(int *arr,int n)
{
    for(int i=n/2-1;i>=0;--i)
    {
        max_heapify(arr,i,n);
    }
}
void heap::max_heapify(int *arr,int i,int n)
{
    int left_child=i*2+1;
    int right_child=i*2+2;
    int largest;
    int flag=0;
    if(left_child<=n-1)
    {
        if(arr[left_child]>arr[i])
        {
            flag=1;
            largest=left_child;
        }
        else
            largest=i;
    }
    if(right_child<=n-1)
    {
        if(arr[right_child]>arr[largest])
        {
            flag=1;
            largest=right_child;
        }
    }
    if(flag==1)
    {
        int temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;
        max_heapify(arr,largest,n);
    }
}
void heap::create_min_heap(int *arr,int n)
{
    for(int i=n/2-1;i>=0;--i)
    {
        min_heapify(arr,i,n);
    }
}
void heap::min_heapify(int *arr,int i,int n)
{
    int left_child=i*2+1;
    int right_child=i*2+2;
    int smallest;
    int flag=0;
    if(left_child<=n-1)
    {
        if(arr[left_child]<arr[i])
        {
            flag=1;
            smallest=left_child;
        }
        else
            smallest=i;
    }
    if(right_child<=n-1)
    {
        if(arr[right_child]<arr[smallest])
        {
            flag=1;
            smallest=right_child;
        }
    }
    if(flag==1)
    {
        int temp=arr[smallest];
        arr[smallest]=arr[i];
        arr[i]=temp;
        min_heapify(arr,smallest,n);
    }
}
void heap::delete_from_heap(int *arr,int &n)
{
    arr[0]=arr[n-1];
    --n;
    max_heapify(arr,0,n);
}
void heap::insertion_in_heap(int *arr,int ele,int &n)
{
    ++n;
    arr[n-1]=ele;
    int i=n-1;
    int j=n/2-1;
    while(i>0&&arr[i]>arr[j])
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i=j;
        j=(j+1)/2-1;
    }
}
void heap::display_heap(int *arr,int n)
{
    for(int i=0;i<n;++i)
        cout<<arr[i]<<" ";
}
int main()
{
    int arr[100];
    int n;
    heap obj;
    int ch;
    int flag1=0;
    int flag2=0;
    do
    {
        cout<<"\nEnter \n1 to input array,\n2 to create max heap,\n3 to create min heap,\n4 to delete from a heap,\n5 for insertion,\n6 to display heap,\n0 to exit: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
        {
            flag1=1;
            flag2=0;
            cout<<"Enter size of array: ";
            cin>>n;
            cout<<"Enter array: "<<endl;
            for(int i=0;i<n;++i)
            cin>>arr[i];
            break;
        }
        case 2:
        {
            if(flag1==1)
            {
                flag2=1;
                obj.create_max_heap(arr,n);
                cout<<"Max heap created"<<endl;
            }
            else
                cout<<"Please input array first"<<endl;
            break;
        }
        case 3:
        {
            if(flag1==1)
            {
                flag2=1;
                obj.create_min_heap(arr,n);
                cout<<"Min heap created"<<endl;
            }
            else
                cout<<"Please input array first"<<endl;
            break;
        }
        case 4:
            obj.delete_from_heap(arr,n);
            break;
        case 5:
            cout<<"Enter element to insert: ";
            int ele;
            cin>>ele;
            obj.insertion_in_heap(arr,ele,n);
            cout<<"Element inserted"<<endl;
            break;
        case 6:
        {
            if(flag2==1)
            {
                obj.display_heap(arr,n);
            }
            else
                cout<<"Please create heap first"<<endl;
            break;
        }
        case 0:
            ch=0;
            break;
        default:
            cout<<"invalid input,try again"<<endl;
        }
    }
    while(ch!=0);
    return 0;
}
