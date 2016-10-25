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
    freopen("2.txt","r",stdin);
    LL n;
    cin >> n;
    string s;
    cin >> s;

    LL cbr = 0;
    LL crb = 0;
    LL cbb = 0;
    LL crr = 0;

    for(int i =0;i<n;i++){
        if (i%2==0){
            if (s[i]!='b')
                cbr++;

            if (s[i]!='r')
                crb++;
        }
        else {
            if (s[i]!='r')
                cbb++;

            if (s[i]!='b')
                crr++;
        }
    }
    cout << min(max(cbb,cbr),max(crb,crr));

return 0;
}

