#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define LL long long int

int main(){
    LL n,a;
    cin >> n >> a;
    vector<LL> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    sort(v.begin(),v.end());

    LL up = -1;

    for(int i=0;i<n;i++){
        if (a<v[i]){
            up = i;
            break;
        }
    }

    cout << v[up-1] <<  " " << v[up];
    cout << max(solve(v,n-2,up-1),solve(v,n-));

    return 0;
    }

