#include<iostream>
using namespace std;
struct node
{
int num;
node *next;
node *prev;	
};
void insert(node **head,int data)
{
    node *temp=new node;
    temp->num=data;
    if(*head==NULL)
    {
        temp->prev=NULL;
        temp->next=NULL;
        *head=temp;
    }
    else
    {
        temp->next=*head;
        temp->prev=NULL;
        *head=temp;
    }
}
int largest(node *head)
{
    int l=-999;
    while(head!=NULL)
    {
        if(head->num>l)
        {
            l=head->num;
        }
        head=head->next;
    }
    return l;
}
int main() 
{
    node *head=NULL;
    int n,data;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        insert(&head,data);
    }
    cout<<largest(head);
    
    
    return 0;
}

