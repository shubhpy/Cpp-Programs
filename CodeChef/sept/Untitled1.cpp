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
    freopen("1.txt","r",stdin);
    LL T;
    cin >> T;

    for(int i= 0;i<T;i++){
        LL L,B,M;
        cin >> L >> B >> M;

        LL sum = 0;
        while(L>1){
            if (L%2 == 0){
                sum = sum + M*(L/2);
                L  = L - L/2;
                sum = sum + B;
                M = M*2;
            }
            else{
                sum = sum + M*((L+1)/2);
                L  = L - (L+1)/2;
                sum = sum + B;
                M = M*2;
            }
        }

        cout  << sum + M<< "\n";
    }
return 0;
}


