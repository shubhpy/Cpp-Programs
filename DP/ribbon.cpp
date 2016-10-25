#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n,a;
    cin >>  n;
    vector<int> dp(4005,0);
    for(int i = 0;i<3;i++){
        cin >> a;
        for(int j=a;j<=n;j++){
            dp[j] = max(dp[j],dp[j-a]+1);
        }
    }

    cout << dp[n];

    return 0;

}
/*
using namespace std;
int n,dp[4005],i,j,a;
int main(){
fill(dp+1,dp+4005,-1e9);
cin>>n;
for(j=1;j<=3;j++)
{
    cin>>a;
    for(i=a;i<=n;i++)dp[i]=max(dp[i-a]+1,dp[i]);
}
cout << -1e9 << "\n";
cout<<dp[n];
return 0;
}
*/

