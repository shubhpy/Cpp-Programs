#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main(){

    long long int n,x;
    cin >> n;

    long long int sum = 0;

    for(int i=0;i<n;i++){
        cin >> x;

        sum+=x-1;

        if (sum%2==0){
            cout << 2 << "\n";
        }
        else{
            cout << 1 << "\n";
        }
    }
    return 0;
        }

