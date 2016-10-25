#include<bits/stdc++.h>
using namespace std;
#define LL long long int

int64_t dpp[500005][500005];

int solve(vector<LL> &dp,int i,int j){

    if (j-i==1){
        dpp[i][j] = 0;
        return 0;
    }

    if (dpp[i][j]==-1){
        if (dp[i]==dp[dp.size()-1] - dp[j-1]){
            if (dp[i] == dp[j-1] - dp[i]){
                dpp[i][j] = 1 + solve(dp,i,j-1) + solve(dp,i+1,j);
            }
            else{
                dpp[i][j] = solve(dp,i,j-1) + solve(dp,i+1,j);
            }

        }
        else if (dp[i]>dp[dp.size()-1] - dp[j-1]){
            dpp[i][j] = solve(dp,i,j-1);
        }
        else{
            dpp[i][j] = solve(dp,i+1,j);
        }
    }
    else{
        return dpp[i][j];
    }

    return dpp[i][j];
}
int main(){

    freopen("3ways.txt","r",stdin);
    LL n,a;
    cin >> n;
    vector<LL> dp(n);

    memset(dpp,-1,sizeof dpp);

    int last = 0;
    for(int i = 0;i<n;i++){
        cin >> a;
        last = last+ a;
        dp[i] = last;
    }

    dpp[0][n-1] = solve(dp,0,n-1);

    cout << dpp[0][n-1] ;
    return 0;
}
