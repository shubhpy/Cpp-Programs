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
    //freopen("3.txt","r",stdin);

    LL N;
    cin >> N;

    LL k = 1;
    LL s = 2;
    string str;

    while(k<N+1){
        for(LL i = s+2;i>0;i+=2){
            if ((i*i - s)%k == 0){
                str = to_string((i*i - s)/k);
                if (str.length()>=17)
                    cout << stoi(str.substr(0,17)) << "\n";
                else
                    cout << (i*i - s)/k << "\n";
                s = i;
                k++;
                break;
                }
            }
    }
    return 0;
}


