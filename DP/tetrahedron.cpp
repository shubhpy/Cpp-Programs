#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

#define LL long long int
#define F first
#define S second

int main(){

//    freopen("DZYSequence.txt","r",stdin);
    LL n;
    cin >> n;
    LL D[n+1];
    LL r[n+1];

    D[1] = 0;
    D[2] = 3;

    r[1] = 1;
    r[2]= 2;

    for(int i = 3;i<=n;i++){
        D[i] = (3*r[i-1])%1000000007 ;
        r[i] = (2*r[i-1] + D[i-1])%1000000007 ;
    }

    cout << D[n]%1000000007 ;

    return 0;
}

