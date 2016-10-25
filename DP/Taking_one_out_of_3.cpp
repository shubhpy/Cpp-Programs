#include <iostream>
using namespace std;

int main() {

    int T;
    cin >> T;
    for(int t = 0;t<T;t++){
        int n;
        cin >> n;
        int v[n];
        for(int i = 0;i<n;i++){
            cin >> v[i];
        }
        if (n==1){
            cout << v[0];
        }
        else if (n==2){
            cout << min(v[0],v[1]);
        }
        else{
            int dp[n];
            dp[0] = v[0];
            dp[1] = v[1];
            dp[2] = v[2];
            for(int i = 3;i<n;i++){
                dp[i] = v[i] + min(dp[i-1],min(dp[i-2],dp[i-3]));
            }
            cout << min(dp[n-1],min(dp[n-2],dp[n-3]));
        }
        cout << "\n";
    }
	return 0;
}
