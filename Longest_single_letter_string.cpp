#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(int l,int e,string s,vector<int> &v,int count,int &ans,vector<vector<int> > &dp){

    if (count==0){
        ans = max(ans,e-l+1);
        dp[l][e] = 1;
        return dp[l][e];
    }
    else{
        dp[l][e] = 0;

        if (dp[l+1][e]!=1 && l+1<s.length()){
            int inc = 0;
            if (v[(int)(s[l] - 'a')] ==2){
                count--;
                inc = 1;
            }
            v[(int)(s[l] - 'a')]--;
            dp[l+1][e] = solve(l+1,e,s,v,count,ans,dp);
            v[(int)(s[l] - 'a')]++;
            if (inc){
                count++;
            }
        }

        if (dp[l][e-1]!=1 && e-1>=0){
            int inc = 0;
            v[(int)(s[e-1] - 'a')]--;
            if (v[(int)(s[e-1] - 'a')] >=2){
                count--;
                inc = 1;
            }
            dp[l][e-1] = solve(l,e-1,s,v,count,ans,dp);
            v[(int)(s[e-1] - 'a')]++;
            if (inc){
                count++;
            }
        }

        return dp[l][e];

    }

}


int main() {

    string s = "ababcde";
    //cin >> s;
    vector<int> v(26,0);

    int count = 0;
    for(int i = 0;i<s.length();i++){
        v[(int)(s[i] - 'a')]++;
        if (v[(int)(s[i] - 'a')] >=2){
            count++;
        }
    }
    int ans = 0;
    vector<vector<int> > dp(s.length()+1,vector<int> (s.length()+1,-1));
    int t = solve(0,s.length()-1,s,v,count,ans,dp);

    cout << ans;

    return 0;
}
