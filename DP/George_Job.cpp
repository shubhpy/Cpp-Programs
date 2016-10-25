#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

#define LL long long int
#define F first
#define S second

int main(){

    freopen("george.txt","r",stdin);
    int n,m,k;
    cin >> n >> m >> k;
    LL v[n];
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }

    LL dp[n][k];

    memset(dp, 0 sizeof dp);

    for(int i = n-1;i>n-m;i--){
        dp[i][]
    }

    for(int i = 0;i<n-1;i++){
        dp[i][k] = max(dp[i+m][k-1],dp[i+1][k]);

    }
















































    LL no=0;
    vector<LL> t;
    int j;
    for(int x = 0;x<m;x++){
        for(int i = x;i<n;){
            no = 0;
            if (n-i>=m){
                for(j = 0;j<m;j++){
                    no = no + v[i+j];
                }
                //cout << no << "\n";
                t.push_back(no);
                i=i+j;
            }
            else{
                break;
            }
        }
    }
    LL ans=  0;
    sort(t.begin(),t.end());
    int s = t.size();
    for(int i = 0;i<k;i++){
        ans +=t[s-1];
        s--;
    }
    cout << ans;
    return 0;
}
