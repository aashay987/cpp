#include <iostream>
int n;
int flag=0;
using namespace std;
bool isSafe(int* board,int* x,int row,int col)
{
    //for column
    for(int i=0;i<row;i++)
    {
        if(x[i]==col)
            return false;
    }
    for(int i=0;i<row;i++)
    {
        if(row-col==i-x[i])
            return false;
    }
    for(int i=0;i<row;i++)
    {
        if(row+col==i+x[i])
            return false;
    }
    for(int i=0;i<row;i++)
    {
        if(row+col==i+x[i])
            return false;
    }
    return true;


}
void makeboard(int *board,int *x,int k)
{
    if(flag==1)
        return;
    //cout<<k<<"\t";;
    //cout<<x[0]<<x[1]<<x[2]<<x[3]<<"\n";
    if(k>=n||k<0)
        {
        for(int i=0;i<n;i++)
        {
            cout<<x[i];
        }
        flag=1;
        return;
        }
    for(int i=k+1;i<n;i++)
    {
        x[i]=-1;
    }
    for(int j=x[k]+1;j<n;j++)
    {
        if(isSafe(board,x,k,j))
        {
            *(board+n*k+j)=1;
            x[k]=j;
            makeboard((int*)board,x,k+1);
        }
    }

    *(board+n*(k-1)+x[k-1])=0;
    makeboard((int*)board,x,k-1);

    return;
}
void b1(int n)
{
    int board[n][n]={0};
    int x[n];
    for(int i=0;i<n;i++)
        x[i]=-1;
    makeboard((int*)board,x,0);
    return;
}

int main()
{
    cout << "Enter n" << endl;
    cin>>n;
    b1(n);
    return 0;
}
