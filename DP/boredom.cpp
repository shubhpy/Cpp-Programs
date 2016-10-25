#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n,x;
    cin >>  n;

    vector<long long int> v(100005,0);

    for(int i = 0;i<n;i++){
        cin >> x;
        v[x]++;
    }
    vector<long long int> dp(100005,0);
    long long int ans = 0;
    for(int i = 100000;i>=0;i--){
        if (v[i]==0){
            dp[i] = dp[i+1];
        }
        else{
            dp[i] = i*v[i] + dp[i+2];
        }
        dp[i] = max(dp[i],dp[i+1]);
        ans  = max(ans,dp[i]);

    }

    cout << ans;

    return 0;

}

