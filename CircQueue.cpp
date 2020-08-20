#include <iostream>

using namespace std;
class Queue{
int front;
int rear;
int size;
int* Q;
public:
    Queue()
    {
        front=rear=0;
        size=10;
        Q=new int[size];
    }
    Queue(int n)
    {
        front=rear=0;
        size=n;
        Q=new int[size];
    }
    void enqueue(int v);
    int dequeue();
    void display();
};

void Queue::enqueue(int c)
{
    if((rear+1)%size==front)
    {
        cout<<"Queue is full";
    }
    else{
        Q[(rear+1)%size]=c;
        rear=(rear+1)%size;
    }
}
int Queue::dequeue()
{
    if(front==rear)
    {
        cout<<"\n Queue is empty";
        return -1;
    }
    else{
        int x;

        front=(front+1)%size;
        x=Q[front];
        return x;
    }
}
void Queue::display()
{
    int i=front+1;
    while(i!=rear+1)
    {
        cout<<Q[i];
        i=(i+1)%size;
    }
}
int main()
{
    Queue q;
    q.enqueue(6);
    q.enqueue(7);
    q.display();
    cout<<"\n";
    q.enqueue(5);
    q.display();
    cout<<"\n";
    int v=q.dequeue();
    cout<<v<<endl;
    q.display();
    return 0;
}
