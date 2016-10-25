#include <iostream>
#include <vector>
#include <cmath>
#include<climits>

using std::vector;
using std::cin;
using std::cout;

void erge(vector<int>& x,int p,int q,int r);
void mergeSort(vector<int>& x,int p,int r);

void mergeSort(vector<int>& x,int p,int r){

        int q;
        if(p<r)
        {
         q=(p+r)/2;
         mergeSort(x,p,q);
         mergeSort(x,q+1,r);
         erge(x,p,q,r);
}
}

void erge(vector<int>& x,int p,int q,int r){

        int n1 = q-p+1;
        int n2 = r-q;

        vector<int> L(n1+1);
        vector<int> R(n2+1);
        for(int i=0;i<n1;i++)
        {
            L[i]=x[p+i];
        }
        for(int j=0;j<n2;j++)
        {
            R[j]=x[q+j+1];
        }

        L[n1]=INT_MAX;
        R[n2] = INT_MAX;

        int i=0, j=0;
        for(int k=p;k<=r;k++)
        {
            if(L[i]<=R[j])
            {
                x[k]=L[i];
                i=i+1;
            }
            else
            {
                x[k]=R[j];
                j=j+1;
            }
        }

        }

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    mergeSort(x,0,n-1);

    for(int i=0;i<n;i++){
        cout <<  x[i] << " ";
    }
    return 0;
}

