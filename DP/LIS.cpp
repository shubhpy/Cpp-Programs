#include <iostream>
#include<cstring>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t =0;t<T;t++){
        int n;
        cin >> n;
        int v[n];
        for(int i = 0;i<n;i++){
            cin >> v[i];
        }
        int dp[n];
        for (int i = 0; i < n; i++ )
            dp[i] = 1;
        //memset(dp,1,sizeof dp);
        int ans = 0;
        for(int i = 1;i<n;i++){
            for(int j = 0;j<i;j++){
                if (v[i]>v[j]){
                    dp[i] = max(dp[i],1+dp[j]);
                    ans = max(ans,dp[i]);
                }
            }
        }

        cout << ans << "\n";
    }
	return 0;
}
