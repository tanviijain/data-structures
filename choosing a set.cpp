#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node *next;
};
struct Node* createNode(int val){
    struct Node *temp;
    temp = new(struct Node);
    temp->data = val;
    temp->next=NULL;
    return temp;
}
void insert(struct Node **head,int data){
    struct Node *P;
    int val;
    val = data;
    P = createNode(data);
    if(*head==NULL){
        *head = P;
        P->next = NULL;
    }
    else {
        P->next = *head;
        *head = P;
    }
}
void display(struct Node *head){
    struct Node *temp;
    int flag=0;
    temp = head;
    while(temp!=NULL){
        if(flag%2==0)
            cout<<temp->data<<" ";
        flag++;
        temp = temp->next;
    }
}
int main()
{
	int number,i,n;
	cin>>n;
	struct Node *head=NULL;
	for(i=n;i>0;i--)
	{
		cin>>number;
		insert(&head,number);
	}
	display(head);
	return 0;
}

