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
    LL i,n;
    cin >>  n;
    for(i=0; i < n ; i++){
        string s;
        cin  >> s;
        LL p = 1%MOD;
        int siz = s.size();
        if (siz!=1){
        for(int j=0;j<s.size();j++){
            if (j==0){
                if (s[j]==s[j+1]){
                    p = (p*1) % MOD;
                }
                else{
                    p = (p*2) % MOD;
                }
            }
            else if (j<siz-1){
                if (s[j]!=s[j+1] && s[j]!=s[j-1] && s[j-1]==s[j+1]){
                    p = (p*2) % MOD;
                }
                else if (s[j]==s[j+1] && s[j]!=s[j-1]){
                    p = (p*2) % MOD;
                }
                else if (s[j]==s[j-1] && s[j]!=s[j+1]){
                    p = (p*2) % MOD;
                }
                else if (s[j]==s[j+1] && s[j]==s[j-1]){
                    p = (p*1) % MOD;
                }
                else if (s[j]!=s[j+1] && s[j]!=s[j-1]){
                    p = (p*3) % MOD;
                }
            }
            else{
                if (s[j]==s[j-1]){
                    p = (p*1) % MOD;
                }
                else{
                    p = (p*2) % MOD;
                }
            }
            }
            cout << "Case #" << i+1 <<  ": " << p << "\n";
        }
    else{
        cout << "Case #" << i+1 <<  ": " << 1 << "\n";
    }
    }

        return 0;
}

