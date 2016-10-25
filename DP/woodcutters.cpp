#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

#define LL long long int
#define F first
#define S second

int main(){

    freopen("woodcut.txt","r",stdin);
    int n;

    cin >> n;

    LL v[n][3];
    int dp[n][3];

    LL a,b;

    for(int i = 0;i<n;i++){
        cin >> a >> b;
        v[i][0] = a-b;
        v[i][1] = a;
        v[i][2] = a+b;
    }

    dp[0][0]= 1;
    dp[0][1]= 0;
    dp[0][2]= 1;

    for(int i = 1;i<n;i++){
        dp[i][0] = 1;
        if (v[i][0]>v[i-1][1]){
            dp[i][0] = max(dp[i][0],1+ max(dp[i-1][0],dp[i-1][1]));
        }
        if (v[i][0]>v[i-1][2]){
            dp[i][0] = max(dp[i][0],1+ dp[i-1][2]);
        }

        dp[i][1] = 0;
        if (v[i][1]>v[i-1][1]){
            dp[i][1] = max(dp[i][1],max(dp[i-1][0],dp[i-1][1]));
        }
        if (v[i][1]>v[i-1][2]){
            dp[i][1] = max(dp[i][1],dp[i-1][2]);
        }

        dp[i][2] = 1;
        if (v[i][1]>v[i-1][1]){
            dp[i][2] = max(dp[i][2],1 + max(dp[i-1][0],dp[i-1][1]));
        }
        if (v[i][1]>v[i-1][2]){
            dp[i][2] = max(dp[i][2],1+ dp[i-1][2]);
        }
    }
    cout <<  max(dp[n-1][0] , max(dp[n-1][1],dp[n-1][2]));
    return 0;
}
