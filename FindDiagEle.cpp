
// Sample code to perform I/O:

#include<iostream>
using namespace std;
class node{
	public:
	int x;
	int y;
	node *next;
}*first,*last;


int main()
{
	int num;
	cin >> num;										// Reading input from STDIN
	while(num>0)
	{
		last=first=NULL;

		int n,n1,n2;
		cin>>n;

		cin>>n1>>n2;
		node* f1= new  node;
		f1->x=n1;
		f1->y=n2;
		first=f1;
		last=first;
		first->next=NULL;
		for(int i=0;i<n-1;i++)
		{
			cin>>n1>>n2;
			node* pt= new  node;
			pt->x=n1;
            pt->y=n2;
            last->next=pt;
            pt->next=NULL;
            last=pt;

		}
		last->next=NULL;
		node *ptr;
        ptr=first;
		while(ptr)
        {

            cout<<ptr->x<<ptr->y<<endl;
            ptr=ptr->next;
        }
		delete first;
		delete last;
		num--;

	}
	return 0;
}

