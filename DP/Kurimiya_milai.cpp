#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

#define LL long long int
#define F first
#define S second

int main(){

    freopen("kuriyama.txt","r",stdin);
    int n;

    cin >> n;
    vector<LL> v(n);
    LL last = 0;
    LL dp[n];
    LL dps[n];

    for(int i = 0;i<n;i++){
        cin >> v[i];
        dp[i] = last + v[i];
        last = dp[i];
    }

    sort(v.begin(),v.end());
    last = 0;
    for(int i = 0;i<n;i++){
        dps[i] = last + v[i];
        last = dps[i];
    }

    int m;
    cin >> m;
    int t,a,b;
    for(int i = 0;i<m;i++){
        cin >> t >> a >> b;
        if (t==1){
            if (a==1){
                cout << dp[b-1]<< "\n";
            }
            else{
                cout << dp[b-1] - dp[a-2] << "\n";
            }
        }
        else{
            if (a==1){
                cout << dps[b-1] << "\n";
            }
            else{
                cout << dps[b-1] - dps[a-2] << "\n";
            }
        }
    }
    return 0;
}

