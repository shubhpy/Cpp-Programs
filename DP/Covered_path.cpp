#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

#define LL long long int
#define F first
#define S second

int main(){

    //freopen("coveredpath.txt","r",stdin);
    int n,m,t,d;
    cin >> n >> m >> t >> d;

    LL ans = n;
    for(int i = 1;i<t;i++){
        for(int x = n+d;x>=n-d;x--){
            if (m >= x-(t-i-1)*d && x+(t-i-1)*d >=m ){
                ans+=x;
                n = x;
                break;
            }
        }
    }

    cout << ans;
    return 0;
}


