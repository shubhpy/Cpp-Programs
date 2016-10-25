#include<iostream>
#include<vector>

using namespace std;


int peak_finder(vector<int>& a,int r,int p){

    int q=r+ (p-r)/2;
    if(a[q]<a[q-1]){
        return peak_finder(a,r,q-1);
        }
    else if(a[q]<a[q+1]){
        return peak_finder(a,q+1,p);
    }
    else{
        return a[q];
        }

}

int main()
{
    int n;
    cin>> n;
    vector<int> a(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
        }
    cout <<
    peak_finder(a,0,n-1);
    return 0;
}
