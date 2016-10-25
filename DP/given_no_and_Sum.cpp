#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;


int dpp[105][905];

bool solve(vector<int> &dp,int s,int m,int mnomx,int &d){

    if (dpp[m][s]==-1){
        if (d){
            dpp[m][s] = false;
            return 0;
        }

        if (m==1){
            if (s>=10 || s<=0){
                dpp[m][s] = false;
                return false;
            }
            else{
                dp[m]= s;
                dpp[m][s] = true;
                return true;
            }
        }

        if (mnomx){
            for(int i = 0;i<=9;i++){
                dp[m] = i;
                dpp[m-1][s-i] = solve(dp,s-i,m-1,mnomx,d);
                if (dpp[m-1][s-i]){
                    for(int j = 1;j<dp.size();j++){
                        cout << dp[j];
                        d = 1;
                    }
                    d = 1;
                    break;
                }
            }
            return 0;
        }
        else{
            for(int i = 9;i>=0;i--){
                dp[m] = i;
                dpp[m-1][s-i] = solve(dp,s-i,m-1,mnomx,d);
                if (dpp[m-1][s-i]){
                    for(int j = 1;j<dp.size();j++){
                        cout << dp[j];
                        d = 1;
                    }
                    d = 1;
                    break;
                }
            }
            return 0;
        }
    }
    else{
        return dpp[m][s];
    }
}



int main(){

    int m,s;
    cin >>  m >> s;

    vector<int> dp(m+1,0);

    if (m==1){
        if (s>=10){
            cout << -1 << " " << -1 ;
        }
        else
            cout << s << " " << s;

        return 0;
    }

    memset(dpp, -1, sizeof dpp);


    int d = 0;

    solve(dp,s,m,0,d);
    if (d==0)
        cout << -1;
    cout << " ";
    d = 0;
    memset(dpp, -1, sizeof dpp);
    solve(dp,s,m,1,d);
    if (d==0)
        cout << -1;

    return 0;

}


