//#include <bits/stdc++.h>

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<iterator>
#include<string>
#include<sstream>
#include<cassert>
#include<ctime>
#include<cmath>
#include<numeric>

#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define oo 2000000000
#define MOD 1000000007
#define LL long long int
#define PII pair<int,int>
#define DEBUG 0

using namespace std;

int main(){
    freopen("2.txt","r",stdin);
    LL T;
    cin >> T;

    for(int i= 0;i<T;i++){
        LL N;
        cin >> N;
        vector<LL> v(N);
        for(int i = 0;i<N;i++){
            cin >> v[i];
        }

        LL d1;
        LL d2 = INT_MIN;
        LL ans;

        d1 = A[1] - A[0];
        ans = A[0];
        for(int i = 2;i<N;i++){
            if (A[i]-A[i-1]!=d1){
                diff++;
            }
        }
    }
return 0;
}



