#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long int

LL solve(vector<LL>  &V,int m,int d,int s,int N){
    if (d<=N){
        if (s>0){
            return max(max(solve(V,m,d+1,s,N) , solve(V,m-V[d-1],d+1,s+1,N)) ,solve(V,m + s*V[d-1],d+1,0,N));
        }
        else{
            return max(solve(V,m,d+1,s,N) , solve(V,m-V[d-1],d+1,s+1,N));
        }
    }
    else{
        return m;
    }
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    freopen("stock_input.txt","r",stdin);
	freopen("stock_output.txt","w",stdout);
    int T;
    cin >> T;
    LL N;
    for(int t=0;t<T;t++){
        cin >> N;
        vector<LL> V(N);
        for(int i=0;i<N;i++){
            cin >> V[i];
        }

        cout << solve(V,0,1,0,N) << "\n";
    }
    return 0;
}
