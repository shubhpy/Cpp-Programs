#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long int
#define MOD 10000000007

int main() {
    freopen("sum_substring_input.txt","r",stdin);
	freopen("sum_substring_output.txt","w",stdout);
    string a; cin >> a;
    unsigned long long sum = 0;
    unsigned long long z=0;
    for(int i = 0; a.size() > i;i++){

    z=(z*10 + (a[i]-'0')*(i+1))%1000000007;
    sum= (sum + z)%1000000007;
    }
    cout << sum%1000000007;
    return 0;
}

/*
int main() {
    freopen("sum_substring_input.txt","r",stdin);
	freopen("sum_substring_output.txt","w",stdout);
    string n;
    cin >> n;
    LL sum = 0;
    LL mul = 1;
    for(LL i=n.length()-1;i>=0;i--){
        /*
        sum +=(((LL)n[i] -48)*(i+1)*mul) % MOD;
        mul+=pow(10,j);
        mul=mul%MOD;
        j++;
        sum = sum%MOD;
    }

    cout << sum;
    return 0;
}
*/
