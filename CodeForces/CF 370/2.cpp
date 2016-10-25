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
    //freopen("2.txt","r",stdin);
	//freopen("out6.txt","w",stdout);
    string s;
    cin >> s;
    //vector<int> vect;
    //vector<vector<LL> > vectQ(Q, vector<LL>(2,0));

    int R= 0;
    int L = 0;
    int U = 0;
    int D = 0;
    for(int i=0;i<s.length();i++){
        if (s[i]=='R'){
            R++;
        }
        else if (s[i]=='U'){
            U++;
        }
        else if (s[i]=='D'){
            D++;
        }
        else if (s[i]=='L'){
            L++;
        }
}

        if (abs(R-L) == 0){
            if (abs(D-U)%2==0){
                cout << abs(D-U)/2;
            }
            else{
                cout << -1;
            }
        }
        else if (abs(D-U) == 0){
            if (abs(R-L)%2==0){
                cout << abs(R-L)/2;
            }
            else{
                cout << -1;
            }
        }
        else if (abs(R-L)==abs(U-D)){
            cout << abs(R-L);
        }
        else {
            cout << -1;
        }

return 0;
}


