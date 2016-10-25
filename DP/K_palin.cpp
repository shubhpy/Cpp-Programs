#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int palin(string s,vector<vector<int> > &dp,int i,int e){
    if (dp[i][e]==-1){
        if (i==e){
            dp[i][e]= 1;
        }
        else if (s[i]==s[e]){
            dp[i][e] = palin(s,dp,i+1,e-1);
        }
        else{
            dp[i][e]=0;
        }
    }
    return dp[i][e];
}
bool ispalin(string s,vector< vector<int> > &dp,int i,int e,int k){
    if (i>=e)
        return 1;
    if (palin(s,dp,i,e))
        return 1;
    if (k==0)
        return 0;
    if (s[i]==s[e])
        return ispalin(s,dp,i+1,e-1,k);
    return ispalin(s,dp,i+1,e,k-1) || ispalin(s,dp,i,e-1,k-1);
}
bool is_k_palin(string s,int k)
{
    int n = s.length();
    vector<vector<int> > dp(n,vector<int>(n,-1));
    return ispalin(s,dp,0,n-1,k);
}
}
int main(){

    int k = 1;
    string s = "abcdecba";
    cout << is_k_palin(s,k);

    }
