#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

string ans;
unordered_map<string,int> dp;
int val3(string n){
    return 100*(int)(n[n.length()-3] - '0') + 10*(int)(n[n.length()-2] - '0') + (int)(n[n.length()-1] - '0') ;
}

int val2(string n){
    return 10*(int)(n[n.length()-2] - '0') + (int)(n[n.length()-1] - '0') ;
}

int val1(string n){
    return (int)(n[n.length()-1] - '0') ;
}

int solve(string n,int &d){
    //cout << n << "\n";
    if (d==1){
        dp[n]=1;
        return 1;
    }

    if (dp[n]==-1){
        return -1;
    }
    else if (dp[n]==1){
        return 1;
    }

    if (n.length()>=3){
        int val = val3(n);
        if (val%8==0){
            d = 1;
            ans = n;
            dp[n]=1;
            return 1;
        }
        else{
            if (dp[n.substr(0,n.length()-1)]==0){
                dp[n.substr(0,n.length()-1)] = solve(n.substr(0,n.length()-1),d);
            }
            if (dp[n.substr(0,n.length()-2) + n.substr(n.length()-1,1)]==0){
                dp[n.substr(0,n.length()-2) + n.substr(n.length()-1,1)] = solve(n.substr(0,n.length()-2) + n.substr(n.length()-1,1),d);
            }
            if (n.length()>3){
                if (dp[n.substr(0,n.length()-3) + n.substr(n.length()-2,2)]==0)
                    dp[n.substr(0,n.length()-3) + n.substr(n.length()-2,2)] = solve(n.substr(0,n.length()-3) + n.substr(n.length()-2,2),d);
            }
            else{
                if (dp[n.substr(n.length()-2,2)]==0)
                    dp[n.substr(n.length()-2,2)] = solve(n.substr(n.length()-2,2),d);
            }
        }
    }
    else if (n.length()==2){
        int val = val2(n);
        if (val%8==0){
            d = 1;
            ans = n;
            dp[n] = 1;
            return 1;
        }
        else{
            if (dp[n.substr(0,n.length()-1)]==0)
                dp[n.substr(0,n.length()-1)] = solve(n.substr(0,n.length()-1),d);
            if (dp[n.substr(n.length()-1,1)]==0)
                dp[n.substr(n.length()-1,1)] = solve(n.substr(n.length()-1,1),d);
        }
    }
    else{
        int val = val1(n);
        if (val%8==0){
            d = 1;
            ans = n;
            dp[n]=1;
            return 1;
        }
        else{
            dp[n]=-1;
            return -1;
        }
    }
}

int main(){
    string n;
    cin >> n;
    int d = 0;
    solve(n,d);
    if (d){
        cout << "YES\n";
        cout << ans;
    }
    else{
        cout << "NO";
    }

return 0;
}


