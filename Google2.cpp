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
    //freopen("in4.txt","r",stdin);
	//freopen("out6.txt","w",stdout);
    LL T;
    cin >> T;
    //vector<int> vect;
    //vector<vector<LL> > vectQ(Q, vector<LL>(2,0));

    for(int t=0;t<T;t++){
        int M;
        cin >>  M;
        LL M1,c1,c2;
        if (M==1){
                cin >>  M1 >>  c1;
                long double r3 = (float)c1/M1;
                cout << "Case #"<< t+1 << ": ";
                printf("%.12Lf  \n" ,  r3 -1);
        }
        else{
            cin >>  M1 >>  c1 >> c2;
        long double r1;
        long double r2;

        r1 = sqrt( (((float)pow(c1,2)/M1)/M1)/4  +  (float)c2/M1 ) +  (float)c1/(2*M1) ;
        r1 =  - sqrt( (((float)pow(c1,2)/M1)/M1)/4  +  (float)c2/M1 ) +  (float)c1/(2*M1) ;
        cout << r1 << " " << r2 << "\n";
        cout << "Case #"<< t+1 << ": ";
        if (r1-1 >  -1 && r1-1 < 1) {

        printf("%.12Lf  \n" , r1-1);
        }
        else{
            printf("%.12Lf  \n" , r2-1);
        }
        }
    }
        return 0;
}

