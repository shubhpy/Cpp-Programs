#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;


long long int solve(vector< vector<long long int> > &ans,vector<int> &v,int n,int m){

    //cout << n << " " << m << "\n";
    if (ans[n][m]!=0){
        return ans[n][m];
    }
    else{
        if (n<0){
            return 0;
        }
        else if (n==0){
            return 1;
        }
        else if (m==1){
            if (n%v[m-1]==0){
                return 1;
            }
            else{
                return 0;
            }
        }

        if (n-v[m-1]<0){
            ans[n][m] = solve(ans,v,n,m-1);
            return ans[n][m];
        }
        else{
            ans[n][m] = solve(ans,v,n,m-1) + solve(ans,v,n-v[m-1],m);
            return ans[n][m];
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N,M;
    cin >> N >> M;
    vector<int> v(M);
    for(int i=0;i<M;i++){
        cin >> v[i];
    }

    sort(v.begin(),v.end());
    vector< vector<long long int> > ans(N+1, vector<long long int>(M+1,0));

    cout << solve(ans,v,N,M);

    return 0;
}
