#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main(){

    freopen("sereja.txt","r",stdin);
    int n ,m,a;
    cin >> n >>  m;
    vector<int> v(n);
    vector<int> dp(n+5);
    unordered_map<int,int> mp;
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    int count = 0;
    for(int i = n-1;i>=0;i--){
        if (mp[v[i]]==0){
            mp[v[i]]++;
            count++;
        }
        dp[i] = count;
    }

    for(int i = 0;i<m;i++){
        cin >> a;
        cout << dp[a-1] <<"\n";
    }
    return 0;
}





