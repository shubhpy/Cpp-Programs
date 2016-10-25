int Solution::calculateMinimumHP(vector<vector<int> > &A) {

    int m = A.size();
    int n = A[0].size();
    vector<vector<pair<int,int> > > dp(m,vector<pair<int,int> > (n));

    int maxneg = 0;

    if (A[0][0]<0){
        dp[0][0].first = A[0][0];
        dp[0][0].second = A[0][0];
    }
    else{
        dp[0][0].first = 0;
        dp[0][0].second = A[0][0];
    }

    if (m==1 && n==1){
            if (dp[0][0].second<0)
                return (-1*dp[0][0].first) + 1;
            else
                return (-1*dp[0][0].first);
    }


    for(int i = 1;i<m;i++){
        if (A[i][0]>=0){
            dp[i][0].first = dp[i-1][0].first;
            dp[i][0].second = dp[i-1][0].second + A[i][0];
        }
        else{
            dp[i][0].second = dp[i-1][0].second + A[i][0];
            dp[i][0].first = min(dp[i-1][0].first , dp[i][0].second);
        }
    }

    for(int i = 1;i<n;i++){
        if (A[0][i]>=0){
            dp[0][i].first = dp[0][i-1].first;
            dp[0][i].second = dp[0][i-1].second + A[0][i];
        }
        else{
            dp[0][i].second = dp[0][i-1].second + A[0][i];
            dp[0][i].first = min(dp[0][i-1].first , dp[0][i].second);
        }
    }


    for(int i = 1;i<m;i++){
        for(int j = 1;j<n;j++){
            if (A[i][j]>=0){
                int um = dp[i-1][j].first ;
                int lm =  dp[i][j-1].first;
                dp[i][j].first = max(um,lm);
                if (um>lm)
                    dp[i][j].second =  dp[i-1][j].second + A[i][j];
                else
                    dp[i][j].second =  dp[i][j-1].second + A[i][j];

            }
            else{
                int um = min(dp[i-1][j].first , dp[i-1][j].second + A[i][j]);
                int lm =  min(dp[i][j-1].first , dp[i][j-1].second + A[i][j]);

                dp[i][j].first = max(um,lm);
                if (um>lm)
                    dp[i][j].second =  dp[i-1][j].second + A[i][j];
                else
                    dp[i][j].second =  dp[i][j-1].second + A[i][j];

            }
        }
    }


    cout << dp[m-1][n-1].first << " " << dp[m-1][n-1].second << "\n";
    if (dp[m-1][n-1].second<0)
        return (-1*dp[m-1][n-1].first) + 1;
    else
        return (-1*dp[m-1][n-1].first);







    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
