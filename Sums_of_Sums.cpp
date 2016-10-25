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

#define getrandom(min, max) ((rand()%(int)(((max) + 1)-(min)))+ (min))
#define PrintDigit(c, d) for(i=0; i < c ; i++)putchar(unit[d]);
#define forn(a,n) for(i=a; i < n ; i++);
using namespace std;

int main(){

    freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
    int T;
    cin >> T;

    for(int t=0;t<T;t++){
        LL N,Q,n;
        cin >> N >> Q;
        vector<LL> vectN;
        for(int i=0;i<N;i++){
            cin >> n;
            vectN.push_back(n);
        }
        vector<vector<LL> > vectQ(Q, vector<LL>(2,0));
        for(int j=0;j<Q;j++){
            cin >> vectQ[j][0] >>  vectQ[j][1];
        }
        LL last = 0;
        vector<LL> vectS;
        for(int c= 0;c<N;c++){
            vectS.push_back(vectN[c]);
            last = vectN[c];
            for(int c2=c+1;c2<N;c2++){
                vectS.push_back(vectN[c2] + last);
                last = vectN[c2] + last;
            }
            last = 0;
        }

        sort(vectS.begin(),vectS.end());

        cout << "Case #" << t+1 <<":" << "\n";

        unsigned long long int ans;
        ans=0;
        for(int j=0;j<Q;j++){
            for(LL k=vectQ[j][0]-1;k<vectQ[j][1];k++){
                ans+=vectS[k];
            }
            cout << ans << "\n";
            ans = 0;
            //cout << accumulate(vectS.begin() + vectQ[j][0] - 1,vectS.begin() + vectQ[j][1],0) << "\n";
        }



    }
        return 0;
}
