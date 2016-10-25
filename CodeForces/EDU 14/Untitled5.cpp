#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define LL long long int

LL solve(LL n,LL c,LL cost,LL x,LL y){

    if (c==n){
        return cost;
    }

    if (c>n){
        return cost + (c-n)*x;
    }

    if (2*c<=n){
        return min(solve(n,c+1,cost+x,x,y),solve(n,2*c,cost+y,x,y));
    }
    else{
        return min(solve(n,c+1,cost+x,x,y),solve(n,2*c,cost+y,x,y));
    }
}

int main(){
    LL n,x,y;

    cin >> n >> x >> y;

    cout << solve(n,1,x,x,y);

    return 0;
    }
