#include <iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    for(int t = 0;t<T;t++){
        int a,b;
        cin >> a;
        int A[a];
        for(int i = 0;i<a;i++){
            cin >> A[i];
        }
        cin >> b;
        int B[b];
        for(int i = 0;i<b;i++){
            cin >> B[i];
        }
        vector<int> dp(b,0);
        for(int i = 0;i<a;i++){
            int c = 0;
            for(int j = 0;j<b;j++){
                if (A[i]==B[j]){
                    if (dp[j]<c  + 1)
                        dp[j] = c+1;
                }
                if (A[i] > B[j]){
                    if (dp[j] > c)
                        c = dp[j];
                }
            }
        }

        cout << *max_element(dp.begin(),dp.end()) << "\n";

    }
	return 0;
}
