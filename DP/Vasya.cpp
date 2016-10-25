#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string f,s;
	cin >> f >> s;
	int dp[n][n][2];
	int dp2[n][n];

	for(int i = 0;i<n;i++){
		for(int j = i;j<n;j++){
			if (i==j)
				dp[i][j][0] = 0;
			else if (f[i]==f[j] || s[i]==s[j])
				dp[i][j][0] = 1;
			else
				dp[i][j][0] = 0;
		}
	}

	for(int j = n-1;j>=0;j--){
		for(int i = j;i>=0;i--){
			if (i==j)
				dp[i][j][1] = 0;
			else
				dp[i][j][1] = dp[i+1][j][1] + dp[i][j][0];
		}
	}

	for(int i = 0;i<n;i++){
		for(int j = i;j<n;j++){
			if (i==j)
				dp2[i][j] = 0;
			else if (j-i==1)
				dp2[i][j] = dp[i][j][0];
			else{
				dp2[i][j]= dp2[i][j-1] +  dp[i][j][1];
			}
		}
	}
	int q;
	cin >> q;
	int l ,r;
	for(int i = 0;i<q;i++){
		cin >> l >> r;
		cout << dp2[l-1][r-1] << "\n";
	}


    return 0;
}
