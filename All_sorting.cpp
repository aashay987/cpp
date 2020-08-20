#include <iostream>

using namespace std;

void BubSort(int *A,int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(A[i]>A[j])
            {
                int temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
    }
    return;
}
void Insort(int *A,int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=A[i];
        int j;
        for(j=i-1;j>=0;j--)
        {

            if(temp<A[j])
            {
                A[j+1]=A[j];
            }
            else
            {
                    break;
            }
        }
        A[j+1]=temp;
    }
    return;
}
int partition(int *A,int l,int h)
{
    int pivot=A[l];
    int i,j;
    i=l;
    j=h;
    do
    {
        do{i++;}while(A[i]<=pivot);
        do{j--;}while(A[j]>pivot);
        if(i<j)
        {
        int temp=A[i];
        A[i]=A[j];
        A[j]=temp;
        }
    }while(i<j);
    int temp=A[j];
    A[j]=A[l];
    A[l]=temp;
    return j;
}
void QuickSort(int *A,int l,int h)
{
    if(l<h)
    {
        int j=partition(A,l,h);
        QuickSort(A,l,j-1);
        QuickSort(A,j+1,h);
    }
}

void Selsort(int *A,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(A[j]<A[min])
            {
                min=j;
            }
        }
        int temp=A[i];
        A[i]=A[min];
        A[min]=temp;

    }
    return;
}
void Display(int *A,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<",";
    }
    return;
}
void merge(int *A,int l,int mid,int h)
{
    int i=l;
    int j=mid+1;
    int k=l;
    int B[h+1];
    while(i<=mid&&j<h)
    {
        if(A[i]>A[j])
            B[k++]=A[j++];
        else
            B[k++]=A[i++];
    }
    for(;i<=mid;i++)
        B[k++]=A[i];
    for(;j<h;j++)
        B[k++]=A[j];
    for(int i=l;i<h;i++)
    {
        A[i]=B[i];
    }

}
void mergeSort(int *A,int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        mergeSort(A,l,mid);
        mergeSort(A,mid,h);
        merge(A,l,mid,h);
    }
}
int main()
{
    int A[]={4,1,6,2,3,8,5};
    int n=sizeof(A)/sizeof(int);
    QuickSort(A,0,n);
    Display(A,n);
    return 0;
}
