#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
};
class BST
{
    node *root;
    node *new_node;
    node *ptr;
public:
    BST()
    {
        root=NULL;
    }
    node* get_root()
    {
        return root;
    }
    void create();
    void in_order(node *);
    void pre_order(node *);
    void post_order(node *);
    node* searching(int);
    node* min_node(node *);
    node* max_node(node *);
    void lev_order();
    void in_order_without_recursion();
    void pre_order_without_recursion();
    void post_order_without_recursion_2_stacks();
    void post_order_without_recursion();
    node* get_parent_node(int);
    void del_node(int);
};
void BST::create()
{
    root=NULL;
    cout<<"Enter data(-1 to terminate): ";
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
                    if(ptr->right!=NULL)
                        ptr=ptr->right;
                    else
                    {
                        ptr->right=new_node;
                        break;
                    }
                }
                else
                {
                    if(ptr->left!=NULL)
                        ptr=ptr->left;
                    else
                    {
                        ptr->left=new_node;
                        break;
                    }
                }
            }
        }
        cout<<"Enter data(-1 to terminate): ";
        cin>>n;
    }
    cout<<"BST created"<<endl;
}
void BST::in_order(node *ptr)
{
    if(ptr==NULL)
        return;
    in_order(ptr->left);
    cout<<ptr->data<<" ";
    in_order(ptr->right);
}
void BST::pre_order(node *ptr)
{
    if(ptr==NULL)
        return;
    cout<<ptr->data<<" ";
    pre_order(ptr->left);
    pre_order(ptr->right);
}
void BST::post_order(node *ptr)
{
    if(ptr==NULL)
        return;
    post_order(ptr->left);
    post_order(ptr->right);
    cout<<ptr->data<<" ";
}
node* BST::searching(int s)
{
    ptr=root;
    while(1)
    {
        if(s==ptr->data)
            return ptr;
        else if(s>ptr->data && ptr->right!=NULL)
            ptr=ptr->right;
        else if(s<ptr->data && ptr->left!=NULL)
            ptr=ptr->left;
        else
            return NULL;
    }
}
node* BST::min_node(node *ptr)
{
    while(ptr->left!=NULL)
        ptr=ptr->left;
    return ptr;
}
node* BST::max_node(node *ptr)
{
    while(ptr->right!=NULL)
        ptr=ptr->right;
    return ptr;
}
void BST::lev_order()
{
    queue<node *>q;
    q.push(root);
    while(!q.empty())
    {
        ptr=q.front();
        cout<<ptr->data<<" ";
        q.pop();
        if(ptr->left!=NULL)
            q.push(ptr->left);
        if(ptr->right!=NULL)
            q.push(ptr->right);
    }
}
void BST::in_order_without_recursion()
{
    stack<node *>s;
    ptr=root;
    while(ptr!=NULL || !s.empty())
    {
        while(ptr!=NULL)
        {
            s.push(ptr);
            ptr=ptr->left;
        }
        ptr=s.top();
        s.pop();
        cout<<ptr->data<<" ";
        ptr=ptr->right;
    }
}
void BST::pre_order_without_recursion()
{
    stack<node *>s;
    s.push(root);
    while(!s.empty())
    {
        ptr=s.top();
        s.pop();
        cout<<ptr->data<<" ";
        if(ptr->right!=NULL)
            s.push(ptr->right);
        if(ptr->left!=NULL)
            s.push(ptr->left);
    }
}
void BST::post_order_without_recursion_2_stacks()
{
    stack<node *>s1,s2;
    s1.push(root);
    while(!s1.empty())
    {
        ptr=s1.top();
        s1.pop();
        s2.push(ptr);
        if(ptr->left!=NULL)
            s1.push(ptr->left);
        if(ptr->right!=NULL)
            s1.push(ptr->right);
    }
    while(!s2.empty())
    {
        ptr=s2.top();
        s2.pop();
        cout<<ptr->data<<" ";
    }
}
void BST::post_order_without_recursion()
{
    stack<node *>s;
    ptr=root;
    do
    {
        while(ptr!=NULL)
        {
            if(ptr->right!=NULL)
                s.push(ptr->right);
            s.push(ptr);
            ptr=ptr->left;
        }
        ptr=s.top();
        s.pop();
        if(ptr->right!=NULL && (!s.empty() && s.top()==ptr->right))
        {
            s.pop();
            s.push(ptr);
            ptr=ptr->right;
        }
        else
        {
            cout<<ptr->data<<" ";
            ptr=NULL;
        }
    }
    while(!s.empty());
}
node* BST::get_parent_node(int s)
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
        else
            return NULL;
    }
}
void BST::del_node(int de)
{
    node *ptr1=searching(de);
    if(ptr1)
    {
        node *par=get_parent_node(ptr1->data);
        if(ptr1->left==NULL && ptr1->right==NULL)
        {
            if(par==NULL)
                root=NULL;
            else if(ptr1->data<=par->data)
                par->left=NULL;
            else
                par->right=NULL;
            delete ptr1;
            cout<<"Element deleted"<<endl;
        }
        else if(ptr1->left==NULL || ptr1->right==NULL)
        {
            if(par==NULL)
            {
                if(ptr1->left==NULL)
                    root=ptr1->right;
                else
                    root=ptr1->left;
            }
            else if(ptr1->data<=par->data)
            {
                if(ptr1->left==NULL)
                    par->left=ptr1->right;
                else
                    par->left=ptr1->left;
            }
            else
            {
                if(ptr1->left==NULL)
                    par->right=ptr1->right;
                else
                    par->right=ptr1->left;
            }
            delete ptr1;
            cout<<"Element deleted"<<endl;
        }
        else
        {
            node *mn=min_node(ptr1->right);
            int m=mn->data;
            del_node(mn->data);
            if(par==NULL)
                root->data=m;
            else
                ptr1->data=m;
        }
    }
    else
        cout<<"Element not found"<<endl;
}
int main()
{
    BST obj;
    int ch;
    do
    {
        cout<<"\nEnter \n1 to create BST,\n2 for in-order,\n3 for pre-order,\n4 for post-order,\n5 for searching,\n6 to find min and max,\n7 for level-order,\n8 for in-order without recursion,\n9 for pre-order without recursion,\n10 for post-order without recursion using 2 stacks,\n11 for post order without recursion using 1 stack,\n12 to check parent,\n13 for deletion,\n0 to exit: ";
        cin>>ch;
        switch(ch)
        {
        case 1:
            obj.create();
            break;
        case 2:
            obj.in_order(obj.get_root());
            break;
        case 3:
            obj.pre_order(obj.get_root());
            break;
        case 4:
            obj.post_order(obj.get_root());
            break;
        case 5:
        {
            cout<<"Enter element to search: ";
            int sr;
            cin>>sr;
            node* res=obj.searching(sr);
            if(res)
                cout<<"Element found"<<endl;
            else
                cout<<"Element not found"<<endl;
            break;
        }
        case 6:
        {
            node *mn=obj.min_node(obj.get_root());
            cout<<"Min element is "<<mn->data<<endl;
            node *mx=obj.max_node(obj.get_root());
            cout<<"Max element is "<<mx->data<<endl;
            break;
        }
        case 7:
            obj.lev_order();
            break;
        case 8:
            obj.in_order_without_recursion();
            break;
        case 9:
            obj.pre_order_without_recursion();
            break;
        case 10:
            obj.post_order_without_recursion_2_stacks();
            break;
        case 11:
            obj.post_order_without_recursion();
            break;
        case 12:
        {
            cout<<"Whose parent you want to check: ";
            int ele;
            cin>>ele;
            node *par=obj.get_parent_node(ele);
            if(par)
                cout<<"Parent is "<<par->data<<endl;
            else
                cout<<"Parent doesn't exist"<<endl;
            break;
        }
        case 13:
            cout<<"Enter element to delete: ";
            int de;
            cin>>de;
            obj.del_node(de);
            break;
        case 0:
            ch=0;
            break;
        default:
            cout<<"Try again"<<endl;
        }
    }
    while(ch!=0);
    return 0;
}

