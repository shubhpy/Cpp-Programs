/*You are required to complete this method*/
int subsequenceCount(string S, string T)
{
    int n = T.length();
    int m = S.length();

    int dp[n][m];

    memset(dp,0,sizeof dp);
    int mx = 0;
    for(int i = 0;i<m;i++){
        if (T[0]==S[i]){
            dp[0][i] = mx+1;
            mx++;
        }
        else{
            dp[0][i] = mx;
        }
    }
    for(int i = 1;i<n;i++){
        for(int j = i;j<m;j++){
            if (T[i]==S[j]){
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            }
            else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }

    return dp[n-1][m-1];

}

