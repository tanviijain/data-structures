#include<iostream>
using namespace std;
struct node
{
    int data;
    int bf=0;
    node *left;
    node *right;
};
class avl
{
    node *root;
    node *new_node;
    node *ptr;
    avl()
    {
        root=NULL;
    }
    void create();
    void display();
    void check_bf(node *);
    node* get_parent(int);
};
void avl::create()
{
    cout<<"Enter element(-1 to terminate): ";
    int n;
    cin>>n;
    while(n!=-1)
    {
        new_node=new node;
        new_node->data=n;
        new_node->left=NULL;
        new_node->right=NULL;
        if(root==NULL)
            root=new_node;
        else
        {
            ptr=root;
            while(1)
            {
                if(n>ptr->data)
                {
                    if(ptr->right==NULL)
                    {
                        ptr->right=new_node;
                        check_bf(ptr->right);
                        break;
                    }
                    else
                        ptr=ptr->right;
                }
                else
                {
                    if(ptr->left==NULL)
                    {
                        ptr->left=new_node;
                        check_bf(ptr->left);
                        break;
                    }
                    else
                        ptr=ptr->left;
                }
            }
        }
        cout<<"Enter element(-1 to terminate): ";
        cin>>n;
    }
}
void avl::display()
{
 }
void avl::check_bf(node *ptr)
{
    node *ptr1=get_parent(ptr);
    while(1)
    {
        node *par=get_parent(ptr1);
        if(par->bf==2)
     }
}
node * avl::get_parent(int s)
{
    ptr=root;
    node *save=NULL;
    while(1)
    {
        if(s==ptr->data)
            return save;
        else if(s>ptr->data && ptr->right!=NULL)
        {
            save=ptr;
            ptr=ptr->right;
        }
        else if(s<ptr->data && ptr->left!=NULL)
        {
            save=ptr;
            ptr=ptr->left;
        }
        return NULL;
    }
}
int main()
{
    avl obj;
    obj.create();
    return 0;
}
