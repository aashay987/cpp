#include <iostream>

using namespace std;
struct Stack{
int top;
char *c;
};
void push(struct Stack &p,char v)
{
    p.top=p.top+1;
    p.c[p.top]=v;
}
void pop(struct Stack &p)
{
    char k;
    k=p.c[p.top];
    p.top=p.top-1;
    return;
}
int isOperand(char v)
{
    if(v=='+'||v=='-'||v=='/'||v=='*')
    {
        return 1;
    }
    return 0;
}
int Pre(char v)
{
    if(v=='+'||v=='-')
    {
        return 1;
    }
    else if(v=='/'||v=='*')
    {
        return 2;
    }
}
int isempty(struct Stack& p)
{
    if(p.top==-1)
    {
        return 1;
    }
    return 0;
}
void disp(struct Stack &p,char*k)
{
    for(int i=0;k[i]!='\0';i++)
    {
        if(isOperand(k[i]))
        {
            //cout<<k[i];
            if(isempty(p)||Pre(p.c[p.top])<Pre(k[i]))
             {
                 push(p,k[i]);
             }
            else
            {
                  while((!isempty(p))&&Pre(p.c[p.top])>=Pre(k[i]))
                  {
                      cout<<p.c[p.top];
                      pop(p);
                  }
                  push(p,k[i]);
            }
        }
        else
        {
            cout<<k[i];
        }
    }
    while(p.top>-1)
    {
        cout<<p.c[p.top];
        p.top=p.top-1;
    }
}
int main()
{
    struct Stack st;
    st.top=-1;
    st.c=new char[20];
    char k[]="a+b-c+d*e/f-g";
    disp(st,k);
}
