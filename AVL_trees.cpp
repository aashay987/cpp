/*#include <iostream>

using namespace std;

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;
    int height;
};

class AVL{
public:
    Node* root;

    AVL(){ root = nullptr; }

    // Helper methods for inserting
    int NodeHeight(Node* p);
    int BalanceFactor(Node* p);
    Node* LLRotation(Node* p);
    Node* RRRotation(Node* p);
    Node* LRRotation(Node* p);
    Node* RLRotation(Node* p);

    // Insert
    Node* rInsert(Node* p, int key);

    // Traversal
    void Inorder(Node* p);
    void Inorder(){ Inorder(root); }
    Node* getRoot(){ return root; }
};

int AVL::NodeHeight(Node *p) {
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int AVL::BalanceFactor(Node *p) {
    int hl;
    int hr;

    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl - hr;
}

Node* AVL::LLRotation(Node *p) {
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    // Update height
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    // Update root
    if (root == p){
        root = pl;
    }
    return pl;
}

Node* AVL::RRRotation(Node *p) {
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    // Update height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    // Update root
    if (root == p){
        root = pr;
    }
    return pr;
}

Node* AVL::LRRotation(Node *p) {
    return nullptr;
}

Node* AVL::RLRotation(Node *p) {
    return nullptr;
}

Node* AVL::rInsert(Node *p, int key) {
    Node* t;
    if (p == nullptr){
        t = new Node;
        t->data = key;
        t->lchild = nullptr;
        t->rchild = nullptr;
        t->height = 1;  // Starting height from 1 onwards instead of 0
        return t;
    }

    if (key < p->data){
        p->lchild = rInsert(p->lchild, key);
    } else if (key > p->data){
        p->rchild = rInsert(p->rchild, key);
    }

    // Update height
    p->height = NodeHeight(p);

    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){
        return RLRotation(p);
    }

    return p;
}

void AVL::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " <<BalanceFactor(p)<<endl;
        Inorder(p->rchild);
    }
}


int main() {

    // LL Rotation
    AVL tll;
    tll.root = tll.rInsert(tll.root, 30);
    tll.root = tll.rInsert(tll.root, 20);
    tll.root = tll.rInsert(tll.root, 10);

    tll.Inorder();
    cout << endl;

    // RR Rotation
    AVL trr;
    trr.root = trr.rInsert(trr.root, 10);
    trr.root = trr.rInsert(trr.root, 20);
    trr.root = trr.rInsert(trr.root, 30);

    trr.Inorder();
    cout << endl;

    return 0;
}*/
#include <iostream>

using namespace std;
class node
{
    public:
    int val;
    node* left;
    node* right;
    int h;
};
node* root=NULL;
int height(node* k)
{
    int h1=(k&&k->left)?(k->left)->h:0;
    int h2=(k&&k->right)?(k->right)->h:0;
    return(h1>=h2?h1+1:h2+1);
}
int bf(node*k)
{
    int h1=(k&&k->left)?(k->left)->h:0;
    int h2=(k&&k->right)?(k->right)->h:0;
    return(h1-h2);
}
node* LLRotation(node* p)
{

node* pl=p->left;
node* plr=pl->right;
pl->right=p;
p->left=plr;
pl->h=height(pl);
//plr->h=height(plr);
p->h=height(p);
if(root==p){
    root=pl;
}
return pl;
}
node* LRRotation(node* p)
{
node *pl=p->left;
node *plr=pl->right;

pl->right=plr->left;
p->left=plr->right;
plr->left=pl;
plr->right=p;
pl->h=height(pl);
plr->h=height(plr);
p->h=height(p);
if(p==root)
    root=plr;
return plr;
}
node* RLRotation(node* p)
{
node *pr=p->right;
node *prl=pr->left;

pr->left=prl->right;
p->right=prl->left;
prl->right=pr;
prl->left=p;
pr->h=height(pr);
prl->h=height(prl);
p->h=height(p);
if(p==root)
    root=prl;
cout<<pr->val<<" "<<pr->h;
cout<<pr->val<<" "<<prl->h;
cout<<p->val<<" "<<p->h;
return prl;
}
node* RRRotation(node* p)
{
node *pr=p->right;
node *prl=pr->left;
pr->left=p;
p->right=prl;
pr->h=height(pr);
prl->h=height(prl);
p->h=height(p);
if(p==root)
    root=pr;
return pr;
}

node* Rinsert(node *a,int v)
{
    //cout<<v;
    if(a==NULL)
    {
        a=new node;
        a->val=v;
        a->h=1;
        a->left=NULL;
        a->right=NULL;
        if(root==NULL)
        {
            root=a;
        }

        //cout<<a->val;
        return a;

    }
    else
    {
        if(v>(a->val))
        {
            a->right=Rinsert(a->right,v);
        }
        else
        {
            a->left=Rinsert(a->left,v);
        }

    }
    a->h=height(a);


    if(bf(a)==2 && bf(a->left)==1)
    {
        cout<<"LL\n";
        return LLRotation(a);
    }
    else if(bf(a)==2 && bf(a->left)==-1)
    {
        cout<<"Lr\n";
        return LRRotation(a);
    }

    else if(bf(a)==-2 && bf(a->left)==1)
    {
        cout<<"rL\n";
        return RLRotation(a);
    }

    else if(bf(a)==-2 && bf(a->left)==-1)
    {
        cout<<"rr\n";
        return RRRotation(a);
    }
    return a;
}
void Disp(node *p)
{
    if(p)
    {
        Disp(p->left);
        cout<<p->val<<" "<<p->h<<" bf: "<<bf(p)<<endl;
        Disp(p->right);

    }
}
int main()
{
 int A[]={5,1,6,3,2
 };
 for(int i=0;i<5;i++)
 {
     root=Rinsert(root,A[i]);
 }
// cout<<root->val;
//cout<<root->left->val;
  // cout<<root->right->val;
 Disp(root);
}
