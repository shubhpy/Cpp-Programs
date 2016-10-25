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
    int k ,r;
    cin >> k >> r;

    if (k%10==0 || k==r){
        cout << 1;
    }
    else{
        for(int i = 1;i<10000000;i++){
            if ((i*k)%10==r || (i*k)%10==0){
                cout << i;
                break;
            }
        }
    }

    return 0;
    }
