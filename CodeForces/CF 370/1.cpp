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
	//freopen("out6.txt","w",stdout);
    LL T;
    cin >> T;
    vector<LL> vect(T);
    //vector<vector<LL> > vectQ(Q, vector<LL>(2,0))

    for(int t=0;t<T;t++){
        cin >> vect[t];
    }
    for(int t=1;t<T;t++){
        cout << vect[t] + vect[t-1] << " ";
}
cout << vect[T-1];


return 0;
}

