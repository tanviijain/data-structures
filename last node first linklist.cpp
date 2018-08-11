#include<iostream>
using namespace std;
 struct Node
{
  int data;
  Node *next;
};
Node *tail;
void create(Node **head,int data)
{
    Node *temp=new Node;
    temp->data=data;
    temp->next=NULL;
    if(*head==NULL)
    {
        *head=temp;
        tail=temp; 
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}

void moveToFront(Node **head)
{
    Node *temp=new Node;
    temp=*head;
    Node *temp2=new Node;
    while((temp->next->next)!=NULL)
    {
        temp=temp->next;
    }
    temp2=temp->next;
    temp->next=NULL;
    temp2->next=*head;
    *head=temp2;
}
void printList(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
void insert(Node **head)
{
    int n,data;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        create(head,data);
    }
    
}
int main()
{
	Node *head=NULL;
	insert(&head);
	moveToFront(&head);
	printList(head);
	return 0;
}
