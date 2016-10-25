#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long int N,x;
    cin >> N;

    vector<long long int> v(N+1);
    for(int i = 1;i<=N;i++){
        cin >> x;
        v[x] = i;
    }
    long long int ans = 0;

    vector<long long int> dp(N+2,0);
    dp[N+1] = 0;
    dp[N] = 1;

    for(int i = N-1;i>=1;i--){
        if (v[i] > v[i+1]){
            dp[i] = dp[i+1];
            ans = max(ans,dp[i]);
        }
        else{
            dp[i] = 1 + dp[i+1];
            ans = max(ans,dp[i]);
        }
    }

    cout << ans;

    return 0;
}
