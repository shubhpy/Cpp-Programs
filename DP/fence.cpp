#include<iostream>
using namespace std;

int v[500005];
long long int dp[500005];

int main(){
    int n , k;
    cin >> n  >> k;
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    long long int sum = 0;
    for(int i = 0;i<k;i++){
        sum = sum + v[i];
    }

    dp[0] = sum;
    long long int mn = dp[0];
    int ans = 0;
    for(int i = 1;i<=n-k;i++){
        dp[i] = dp[i-1] - v[i-1] + v[i+k-1];
        if (mn>dp[i]){
            ans = i;
            mn = dp[i];
        }
    }

    cout << ans+1;

return 0;
}
