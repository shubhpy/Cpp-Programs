/*You are required to complete this method*/
int wildCard(string pattern,string str)
{
    int p = pattern.length();
    int s = str.length();

    int dp[s][p];

    for(int i = 0;i<s;i++){
        if (pattern[0]!='*'){
            if (i==0){
                if (str[0]==pattern[0] || pattern[0]=='?')
                    dp[i][0]=1;
                else
                    dp[i][0]=0;
            }
            else{
                dp[i][0]=0;
            }
        }
        else if (pattern[0]=='*')
            dp[i][0]=1;
    }
    for(int i = 1;i<p;i++){
        if (pattern[i]=='?')
            dp[0][i]=0;
        else if (str[0]==pattern[i] || pattern[i]=='*')
            dp[0][i]=dp[0][i-1];
        else
            dp[0][i]=0;
    }

    for(int i = 1;i<s;i++){
        for(int j = 1;j<p;j++){
            if (pattern[j]=='*')
                dp[i][j]=dp[i-1][j-1] || dp[i][j-1];
            else if (pattern[j]==str[i] || pattern[j]=='?')
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=0;
        }
    }
    return dp[s-1][p-1];
}
