#include <bits/stdc++.h>

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
    LL b ,d,s;
    cin >> b >> d >> s;
    LL total = 0;
    LL ans = 0;
    if (b==d && d==s){
        ans  = 0;
    }
    else{
        LL x = max(b,max(d,s));
        if (x==b && x==d){
            ans  = min(3*(b) - 1  - b - d -s ,3*d - b - d -s);
        }
        else if (x==b && x==s){
            ans = min(3*(b) - b - d -s , 2 +  3*(s-1) - b - d -s);
        }
        else if (x==s && x==d){
            ans  = min(3*d -1 -  b - d -s , 3*s - b - d -s);
        }
        else if (x==b){
            total = 1 +  3*(b-1);
            ans  = total - b - d -s;
        }
        else if (x==d){
            total = 4 +  3*(d-2);
            ans =  total - b - d -s;
        }
        else if (x==s){
            total = 1 +  3*(s-1);
            ans  = total - b - d -s;
        }
    }
    cout <<  ans;
    return 0;
    }
