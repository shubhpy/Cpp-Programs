#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n,x;
    cin >>  n;

    vector<int> v(n);

    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    int count;
    int zero;
    int ones;
    if (v[0]){
        count = 0;
        ones = 1;
        zero  = 0;
    }
    else{
        count = 1;
        ones= 0;
        zero = 1;
    }

    for(int i = 1;i<n;i++){
        if (v[i]){
            ones++;
            count--;
        }
        else{
            count++;
            zero = max(zero,count);
            }
    }
    if (ones==n){
        cout << n-1;
    }
    else{
        cout << ones+  zero;
    }

    return 0;

}


