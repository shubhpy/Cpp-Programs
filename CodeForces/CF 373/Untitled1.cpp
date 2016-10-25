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
    //freopen("1.txt","r",stdin);

    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0;i<n;i++){
        cin >> v[i];
    }

    if (n==1){
        if (v[0]==0){
            cout << "UP";
        }
        else if (v[0]==15)
            cout << "DOWN";
        else
            cout << -1;
        return 0;
    }

    bool inc = false;
    bool dec = false;

    for(int i = 1;i<n;i++){
        if (v[i]>v[i-1]){
            inc = 1;
            dec = 0;
        }
        else{
            inc = 0;
            dec = 1;
        }
    }

    if (inc==1){
        if (v[n-1]==15){
            cout << "DOWN";
        }
        else{
                cout << "UP";
        }
    }
    else{
        if (v[n-1]==0){
            cout << "UP";
        }
        else{
            cout << "DOWN";
        }
    }



return 0;
}


