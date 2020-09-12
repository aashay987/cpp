#include <iostream>
# define INF 0x3f3f3f3f
using namespace std;
class dist{
public:
    int u;
    int d;
};
class q1{
    int *x;
    int front;
    int last;
    int size;

public:
    void insert(int );
    int remove();
    int isempty();
    q1(int n)
    {
        x=new int[n];
        size=n;
        front=0;
        last=0;
    }
};
void q1::insert(int a)
{
    last=(last+1)%size;
    x[last]=a;
}
int q1::remove()
{
    front=(front+1)%size;
    return x[front];
}
int q1::isempty()
{
    if(front==last)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
class queue{
public:
int front;
int last;
int size;
dist *q;
queue(int n)
{
    q= new dist[n];
    size=n;
    front=0;
    last=0;
}
void add(int u,int v);
dist remove();
int empty();
};
int queue::empty()
{
    if(front==last)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void queue::add(int u,int v)
{
    last=(last+1)%size;
    q[last].d=u;
    q[last].u=v;
    return;
}
dist queue::remove()
{
    front=(front+1)%size;
    return (q[front]);
}
class edge
{
public:
int u;
int w;
edge* next;
};
class graph{
int v;
edge** list;
int* visited1;
public:
graph(int a)
{
    v=a;
    list=new edge*[a+1];
    for(int i=0;i<v;i++)
    {
        list[i]=NULL;
    }
    visited1=new int[v];
    for(int i=0;i<v;i++)
    {
        visited1[i]=0;
    }
}
void addedge(int u1,int v1,int w1);
void shortest_path(int src);
void BFS(int x);
void DFS(int x);
void print()
{
    for(int i=0;i<v;i++)
    {
        cout<<" "<<i<<" : ";
        edge *p=list[i];
        while(p)
        {
            cout<<p->u<<" - "<<p->w<<" . ";
            p=p->next;
        }
        cout<<"\n";
    }
}
};
void graph::addedge(int u1,int v1,int w1)
{
    if(list[u1]==NULL)
    {
        list[u1]=new edge;
        list[u1]->u=v1;
        list[u1]->w=w1;
        list[u1]->next=NULL;
    }
    else
    {
        edge*p=list[u1];
        while(p->next)
        {
            p=p->next;
        }
        edge*q=new edge;
        q->u=v1;
        q->w=w1;
        q->next=NULL;
        p->next=q;
    }

    if(list[v1]==NULL)
    {
        list[v1]=new edge;
        list[v1]->u=u1;
        list[v1]->w=w1;
        list[v1]->next=NULL;
    }
    else
    {
        edge*p=list[v1];
        while(p->next)
        {
            p=p->next;
        }
        edge*q=new edge;
        q->u=u1;
        q->w=w1;
        q->next=NULL;
        p->next=q;
    }


}
void graph::shortest_path(int src) //Dijakstra's Algorithm
{
    edge *p=list[src];
    //k=v-1;
    int dista[v];
    for(int i=0;i<v;i++)
    {
        dista[i]=INF;
    }
    dista[src]=0;
    int u=src;
    queue q1(v);
    q1.add(0,src);
    while(!q1.empty())
    {
        dist a1;
        a1=q1.remove();
        int x=a1.u;
        edge *p=list[x];
        while(p)
        {
            int des=p->u;
            int we=p->w;
            if(dista[des]>dista[x]+we)
            {
                dista[des]=dista[x]+we;
                q1.add(dista[des],des);
            }
            p=p->next;
        }
    }
    for(int i=0;i<v;i++)
    {
        cout<<" "<<i<<" : "<<dista[i]<<endl;
    }
}
void graph::BFS(int x)
{
 edge *p;
 int visited[v]={0};
 visited[x]=1;
 p=list[x];
 q1 z(v);
 z.insert(x);
 while(!z.isempty())
 {
     int cz=z.remove();
     cout<<cz<<" ";
     p=list[cz];
     while(p)
     {
         int ks=p->u;
         if(visited[ks]==0)
         {
             visited[ks]=1;
             z.insert(ks);
         }
         p=p->next;
     }
 }
}

void graph::DFS(int x)
{

 visited1[x]=1;
 cout<<x<<" ";

 edge *p=list[x];
 while(p)
 {
     //cout<<" "<<p->u<<" ";
     if(visited1[p->u]==0)
     {
        DFS(p->u);
     }
     p=p->next;
 }
}
int main()
{
     int V = 9;
    graph g(V);

    //  making above shown graph
    g.addedge(0, 1, 4);
    g.addedge(0, 7, 8);
    g.addedge(1, 2, 8);
    g.addedge(1, 7, 11);
    g.addedge(2, 3, 7);
    g.addedge(2, 8, 2);
    g.addedge(2, 5, 4);
    g.addedge(3, 4, 9);
    g.addedge(3, 5, 14);
    g.addedge(4, 5, 10);
    g.addedge(5, 6, 2);
    g.addedge(6, 7, 1);
    g.addedge(6, 8, 6);
    g.addedge(7, 8, 7);

    //g.shortest_path(0);
    g.print();
     cout<<"\n";
    g.BFS(0);
    cout<<"\n";
    g.DFS(0);

    return 0;
}
