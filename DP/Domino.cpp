#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<unordered_map>

using namespace std;
#define MOD 1000000007
#define LL long long int
#define F first
#define S second

LL dp[505][505];

int main(){

    freopen("domino.txt","r",stdin);
    int h,w;
    cin >>  h >> w;

    memset(dp,0,sizeof dp);

    vector<string> v(h);
    for(int i = 0;i<h;i++){
        cin >> v[i];
    }
    int i = 0;
    for(int j = 0;j<w-1;j++){
        if (v[i][j]=='.' && v[i][j+1]=='.'){
            dp[i][j+1] = 1+ dp[i][j];
        }
        else{
            dp[i][j+1] = dp[i][j];
        }
    }

    int j = 0;
    for(i = 0;i<h-1;i++){
        if (v[i][j]=='.' && v[i+1][j]=='.'){
            dp[i+1][j] = 1+ dp[i][j];
        }
        else{
            dp[i+1][j] = dp[i][j];
        }
    }


    dp[0][0] = 0;
    for(int i = 1;i<h;i++){
        for(int j = 1;j<w;j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            if (v[i][j]=='.' && v[i-1][j]=='.'){
                dp[i][j]++;
            }
            if (v[i][j]=='.' && v[i][j-1]=='.'){
                dp[i][j]++;
            }
        }
    }

    int q,r1,r2,c1,c2;
    cin >> q;

    for(i = 0;i<q;i++){
        cin >> r1 >> c1 >> r2 >> c2 ;
        r1--;
        c1--;
        r2--;
        c2--;
        int ans =  dp[r2][c2];

        if (r1>0 && c1>0){
            ans = ans + dp[r1-1][c1-1];
        }
        if (r1>0){
            ans = ans - dp[r1-1][c2];
        }
        if (c1>0){
            ans = ans - dp[r2][c1-1];
        }

        int m1 = 0;
        for(int a = r1;a<=r2;a++){
            if (c1>0){
                if (v[a][c1]=='.' && v[a][c1-1]=='.'){
                    m1++;
                }
            }
        }
        int m2 = 0;
        for(int b = c1;b<=c2;b++){
            if (r1>0){
                if (v[r1][b]=='.' && v[r1-1][b]=='.'){
                    m2++;
                }
            }
        }
        cout << ans -m1-m2 << "\n";
    }
    return 0;
}


