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
    LL x,y;
    cin >> x >> y;

    LL dif = (x - y);
    int b = 1;
    LL i = y;
    int ans = 0;
    while(b){
        if (i>dif){
            ans = 0;
            b = 0;
        }
        else if (dif%i==0){
            ans = dif/i;
            b = 0;
        }
        else{
            i++;
        }
    }

    cout << ans+3;

return 0;
}


