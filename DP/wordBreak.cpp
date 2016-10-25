#include <iostream>
#include<string>
#include<unordered_map>
#include <string.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t =  0;t<T;t++){
	    int n;
	    string s,str;
	    cin >> n;
	    unordered_map<string,int> mp;
	    for(int i = 0;i<n;i++){
	        cin >> s;
	        mp[s]=1;
	    }
	    cin >> str;
	    int l = str.length();
	    int dp[l][l];
	    memset(dp,0,sizeof dp);

	    int len = 0;
	    while(len<=l){
            for(int i = 0;i<l-len;i++){
                if (mp[str.substr(i,len+1)]==1){
                    dp[i][i+len] = 1;
                }
                else{
                    for(int j = i;j<i+len;j++){
                        if (dp[i][i+len]){
                            break;
                        }
                        dp[i][i+len] = (dp[i][j] && dp[j+1][i+len]);
                    }
                }
            }
            len++;
	    }
	   // for(int i = 0;i<l;i++){
	   //     for(int j = 0;j<l;j++){
	   //         cout << dp[i][j] << " ";
	   //     }
	   //     cout << "\n";
	   // }
	    cout << dp[0][l-1] << "\n";
	}
	return 0;
}
