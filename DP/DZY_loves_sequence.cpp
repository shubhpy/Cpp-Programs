#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

#define LL long long int
#define F first
#define S second

int main(){

    //freopen("DZYSequence.txt","r",stdin);
    int n;
    cin >> n;
    vector<LL> v(n);
    vector<vector<LL> > dp(n,vector<LL>(4));

    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    int count = 0;
    int start = 0;
    int i;
    for( i= 1;i<n;i++){
        if (v[i]<=v[i-1]){
            dp[count][0] = start;
            dp[count][1]= v[start];
            dp[count][2]= v[i-1];
            dp[count][3] = i- start;
            start = i;
            count++;
        }
    }
    if (v[i]<=v[i-1]){
        dp[count][0] = start;
        dp[count][1]= v[start];
        dp[count][2]= v[i-1];
        dp[count][3] = i- start;
        count++;
    }
    LL mx = -1;
    for(i = 1;i<count;i++){
        if (dp[i][3]>1){
            if (v[dp[i][0] + 1] > dp[i-1][2] + 1){
                mx = max(mx,dp[i][3]+dp[i-1][3]);
            }
        }
        if (dp[i-1][3]>1){
            if (v[dp[i-1][0]  + dp[i-1][3] - 2 ] < dp[i][1] - 1){
                mx = max(mx,dp[i][3]+dp[i-1][3]);
            }
        }
        mx = max(mx,1+dp[i-1][3]);
    }

    mx = max(mx,1+dp[count-1][3]);
    cout << mx;
    return 0;
}
