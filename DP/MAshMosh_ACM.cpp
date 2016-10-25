#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>


using namespace std;

#define MOD 1000000007
#define LL long long int
#define F first
#define S second

LL dp[2005][2005];

int main(){

    int n,k;
    cin >> n >> k;

    LL s=0;
    dp[0][1]=1;

    for(int i = 0;i<k;i++){
        for(int j = 1;j<=n;j++){
            for(int p = j;p<=n;p+=j){
                (dp[i+1][p]+=dp[i][j])%=MOD;
            }
        }
    }
    for(int i=1;i<=n;++i)
        (s+=dp[k][i])%=MOD;
    cout << s ;

    return 0;
}

