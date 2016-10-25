#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 0;t<T;t++){
        int n;
        cin >> n;
        int v[n];
        for(int i = 0;i<n;i++)
            cin >> v[i];
        int dp[n][n];
        for(int j = 1;j<n;j = j+2){
            for(int i = 0;i<n-j;i++){
                if (j==1)
                    dp[i][i+j] = max(v[i],v[i+j]);
                else
                    dp[i][i+j] = max(v[i] + min(dp[i+1][i+j-1],dp[i+2][i+j]),v[i+j] + min(dp[i][i+j-2],dp[i+1][i+j-1]));
            }
        }
        cout << dp[0][n-1] << "\n";
    }
	return 0;
}
