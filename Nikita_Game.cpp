#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long int
LL solve(vector<LL> &V,int l,int r,LL sum){
    if (sum%2==1){
        return 0;
    }
    else{
        LL half = sum/2;
        //cout << l << " " << r  << " " << sum << "\n";
        LL jod = 0;
        bool done = false;
        int i=l;
        if (l==r){
            return 0;
        }
        else{
             if (jod==half){
                return 1 + max(solve(V,l,i,half),solve(V,i+1,r,half));
             }
             else{
                    for(i=l;i<=r;i++){
                    if (jod==half){
                    done  = true;
                    break;

                    }
                    else{
                    jod+=V[i];
                    }
                    }

                    if (done){
                    return 1 + max(solve(V,l,i,half),solve(V,i,r,half));
                    }
                    else{
                    return 0;
                    }
             }
        }
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    freopen("Nikita.txt","r",stdin);
	freopen("ansNikita.txt","w",stdout);
    int T;
    cin >> T;
    LL N;
    for(int t=0;t<T;t++){
        cin >> N;
        LL sum = 0;
        vector<LL> V(N);
        for(int i = 0;i<N;i++){
            cin >> V[i];
            sum += V[i];
        }
        cout <<  solve(V,0,N-1,sum) << "\n";
    }
    return 0;
}
