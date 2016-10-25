#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define f first
#define s second
#define oo 2000000000
#define MOD 1000000007
#define LL long long int
#define PII pair<int,int>
#define DEBUG 0

using namespace std;

int main(){
    //freopen("1.txt","r",stdin);
	//freopen("out6.txt","w",stdout);

    LL N,C;
    cin >> N >> C;
    vector<LL> vect(N);
    for(int t=0;t<N;t++){
        cin >> vect[t];
    }
    //vector<vector<LL> > vectQ(Q, vector<LL>(2,0))

    LL count = 1;

    for(int t=1;t<N;t++){
        if (vect[t]-vect[t-1]>C){
            count = 1;
        }
        else{
            count++;
        }
    }


    cout << count;
    return 0;
}


