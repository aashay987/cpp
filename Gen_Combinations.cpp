#include <iostream>

using namespace std;
int pow(int a,int b)
{
    int res=1;
    for(int i=0;i<b;i++)
    {
        res=res*a;
    }
    return res;
}
void gen(int l[],int size)
{
    int counter=0;
    int n=pow(2,size);
    //cout<<n<<endl;
    while(counter<n)
    {
        int j=1;
        cout<<"{";
        for(int i=0;i<size;i++)
        {

            //cout<<counter<<" "<<j<<endl;
            if(counter&j)
            {
                cout<<l[i]<<" ";
            }
            j=j<<1;
        }
        cout<<"} ";
        counter++;
    }
}
int main()
{
    int l[]={1,2,3};
    gen(l,3);
    //cout<<pow(2,3);
    return 0;
}
