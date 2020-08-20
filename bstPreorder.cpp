#include <iostream>

using namespace std;
class node{
public:
node* lchild;
int val;
node* rchild;
};
class stack{
public:
int top;
node** l;
void push(node*p);
node * pop();
node *stacktop();
stack()
{
    l=new node*[50];
    top=-1;
}
}st;
void stack::push(node *p)
{
    l[++top]=p;
    return;
}
node* stack::pop()
{
    return(l[top--]);
}
node* stack::stacktop()
{
    return(l[top]);
}

node* bst(int pre[],int n)
{
    int i=0;
    node *root=new node;
    root->lchild=root->rchild=NULL;
    root->val=pre[i++];
    node*p=root;
    while(i<n)
    {
        if(pre[i]<p->val)
        {
            node* t=new node;
            t->val=pre[i++];
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            st.push(p);
            p=t;
        }
        else
        {
            if(pre[i]>p->val&&(st.top==-1||st.l[st.top]->val>pre[i]))
            {
            node* t=new node;
            t->val=pre[i++];
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            //st.push(p);
            p=t;
            }
            else
            {
                p=st.pop();
            }
        }
    }
    return root;
}
void disp(node *root)
{
    if(root)
    {
     disp(root->lchild);
     cout<<root->val<<" ";
     disp(root->rchild);
    }
}
int main()
{
    node* root;
    int p[]={10, 5, 1, 7, 40, 50};
    root=bst(p,6);
    disp(root);
    return 0;
}

