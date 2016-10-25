#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<cmath>

using namespace std;
#define LL long long int
#define fi first
#define se second


LL solve(vector<LL> &c,vector<string> &sv ,LL i,LL j,int r){

        if (r==1){
            reverse(sv[i].begin(),sv[i].end());
        }

        if (j==c.size()-1){
            if (sv[i]<=sv[j]){
                return 0;
            }
            else{
                return min(c[i],c[j]);
            }
        }

        if (sv[i]<sv[j]){
            return min(c[j] + solve(c,sv,i+1,j+1,1),solve(c,sv,i,j+1,0));
        }
        else{
            return (c[i]+solve(c,sv,i+1,j+1,0));
        }
}


int main(){
        LL n;

        cin >> n;


        vector<LL> c(n);
        vector<string> sv(n);
        for(LL i=0;i<n;i++){
            cin >> c[i];
        }

        for(LL i=0;i<n;i++){
            cin >> sv[i];
        }

        cout << solve(c,sv,0,1,0);


        return 0;
    }


