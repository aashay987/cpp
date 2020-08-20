/*BST Insert and Search
#include <stdio.h>
#include <stdlib.h>
struct node
{
 struct node *lchild;
 int data;
 struct node *rchild;
}*root=NULL;
void Insert(int key)
{
 struct node *t=root;
 struct node *r=NULL,*p;

 if(root==NULL)
 {
 p=(struct node *)malloc(sizeof(struct node));
 p->data=key;
 p->lchild=p->rchild=NULL;
 root=p;
 return;
 }
 while(t!=NULL)
 {
 r=t;
 if(key<t->data)
 t=t->lchild;
 else if(key>t->data)
 t=t->rchild;
 else
 return;
 }
 p=(struct node *)malloc(sizeof(struct node));
 p->data=key;
 p->lchild=p->rchild=NULL;

 if(key<r->data) r->lchild=p;
 else r->rchild=p;
}
void Inorder(struct node *p)
{
 if(p)
 {
 Inorder(p->lchild);
 printf("%d ",p->data);
 Inorder(p->rchild);
 }
}
struct node * Search(int key)
{
 struct node *t=root;

 while(t!=NULL)
 {
 if(key==t->data)
 return t;
 else if(key<t->data)
 t=t->lchild;
 else
 t=t->rchild;
 }
 return NULL;
}
int main()
{
 struct node *temp;

 Insert(50);
 Insert(10);
 Insert(40);
 Insert(20);
 Insert(30);

 //Delete(root,30);

 Inorder(root);
 printf("\n");

 temp=Search(20);
 if(temp!=NULL)
 printf("element %d is found\n",temp->data);
 else
 printf("element is not found\n");

 return 0;
}
*/

#include <iostream>
#include<stdlib.h>
using namespace std;

struct node{
node* lchild;
int data;
node* rchild;
}*root=NULL;

void Insert(int key)
{
 struct node *t=root;
 struct node *r=NULL,*p;

 if(root==NULL)
 {
 p=new node;
 p->data=key;
 p->lchild=p->rchild=NULL;
 root=p;
 return;
 }
 while(t!=NULL)
 {
 r=t;
 if(key<t->data)
 t=t->lchild;
 else if(key>t->data)
 t=t->rchild;
 else
 return;
 }
 p=(struct node *)malloc(sizeof(struct node));
 p->data=key;
 p->lchild=p->rchild=NULL;

 if(key<r->data) r->lchild=p;
 else r->rchild=p;
}


void Inorder(struct node *p)
{
 if(p)
 {
 Inorder(p->lchild);
 printf("%d ",p->data);
 Inorder(p->rchild);
 }
}
node* Search(int val)
{
    node* t=root;
    while(t!=NULL)
    {
        if(val==t->data)
        {
            return t;
        }
        else if(val>t->data)
        {
            t=t->rchild;
        }
        else
            t=t->lchild;
    }
    //t=NULL;
    return NULL;

}
int Height(node *p)
{
    int x,y;
    if(p==NULL)
        return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return (x>y)?x+1:y+1;
}
node* InPre(node*p)
{
    while(p&&p->rchild!=NULL)
        p=p->rchild;
    return p;
}

node* InSuc(node*p)
{
    while(p&&p->lchild!=NULL)
        p=p->lchild;
    return p;
}

node* Delete(int val,node* p)
{
    struct node*q;
    if(p==NULL)
    {
        return NULL;
    }
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
            root=NULL;
        delete p;
        return NULL;
    }

    if(p->data>val)
    {
        p=Delete(val,p->lchild);
    }
    else if(p->data<val)
    {
        p=Delete(val,p->rchild);
    }
    else
    {
        if(Height(p->lchild)<Height(p->rchild))
        {

            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(q->data,p->lchild);
        }
        else
        {
            q=InSuc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(q->data,p->rchild);
        }
    }
    return p;

}
int main()
{
    struct node *v;
    Insert(5);
    Insert(7);
    Insert(8);
    Insert(9);
    Insert(1);
    Insert(4);
    Insert(6);
    Inorder(root);
    cout<<endl;
    //cout<<root->lchild->data<<root->rchild->data<<endl;
    Delete(7,root);
    cout<<"\n";
    Inorder(root);
    v=Search(12);
    if(v)
    cout<<"\n"<<v->data;
    else
        cout<<"\n Not found";
    return 0;
}

