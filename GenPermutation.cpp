#include <iostream>

using namespace std;

void per(int* A,int l,int r)
{
    if(l==r)
    {
        for(int j=0;j<r;j++)
        {
            cout<<A[j];
        }
        cout<<"\n";
    }
    else
    {
        for(int i=l;i<r;i++)
        {
            int temp=A[l];
            A[l]=A[i];
            A[i]=temp;

            per(A,l+1,r);

            temp=A[l];
            A[l]=A[i];
            A[i]=temp;
        }
    }
}
int main()
{
    int A[3]={0};
    for(int i=0;i<3;i++)
    {
        A[i]=i+1;
    }
    per(A,0,3);
    return 0;
}
