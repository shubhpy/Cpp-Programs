#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000009
#define LL long long int

struct record{

    LL bl;
    LL l;
    LL siz;
    LL count;

};

LL solve(vector<LL> &v,LL bl,LL l,LL siz,LL s){

    if (s>v.size()-1){
        return (bl+l)%MOD;
    }
    return (solve(v,bl+l,v[s],1,s+1) + solve(v,bl,l + (l/siz) + (siz+1)*v[s],siz+1,s+1))%MOD;
}


int main() {
    freopen("summing.txt","r",stdin);
    LL n;
    cin >> n;

    vector<LL> v(n);

    for(int i = 0;i<n;i++){
        cin >> v[i];
    }

    cout << solve(v,0,v[0],1,1);

    return 0;
}
