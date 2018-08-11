#include<iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
void insert(node **head,int data)
{
    node *temp=new node;
    temp->data=data;
    temp->next=*head;
    *head=temp;
}
void display(node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=(head->next);
    }       
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
    display(head);

    return 0;
}
