/* C++ Program to implement Merge Sort */

#include<iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void quick_sort(int [],int ,int );
int quick_partition(int [],int,int );

void quick_sort(int a[],int l,int r)
    {
        if(l<r)
        {
         int k = l + rand() % (r-l +1);
         int tem=a[k];
         a[k]=a[l];
         a[l]=tem;

         int m=quick_partition(a,l,r);
         quick_sort(a,l,m-1);
         quick_sort(a,m+1,r);
        }
        else{
        return ;}
    }

 int quick_partition (int a[],int l,int r){

    int pivot = a[l];
    int j = l;
    int temp=0;

    for(int i=l+1;i<r;i++){
        if (a[i] <= pivot){
            j++;
        temp=a[j];
        a[j]=a[i];
        a[i]=temp;
        }
    }
    temp=a[j];
    a[j]=a[l];
    a[l]=temp;

    return j;

}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    int l=1,r=n;

    quick_sort(a,l,r);
    for(int i=1;i<=r;i++)
    {
    cout<<a[i]<< " ";
    }
    return 0;
}
