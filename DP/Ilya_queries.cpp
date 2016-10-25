#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    freopen("ilya_q.txt","r",stdin);
    string s;
    cin >>  s;
    int n = s.length();
    vector<int> dp(n+2);

    dp[1]= 0;
    for(int i = 2;i<=n;i++){
        if (s[i-2]==s[i-1])
            dp[i] = dp[i-1] + 1;
        else
            dp[i] = dp[i-1];
    }

    int q;
    cin >> q;
    int a,b;

    for(int i = 0;i<q;i++){
        cin >> a >> b;
        cout << dp[b] - dp[a] << "\n";
    }
    return 0;
}




