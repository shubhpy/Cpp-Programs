#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long int

int main() {
    LL n,q;
    cin >> n >> q;
    vector<LL> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[n];
    }
    LL x;
    sort(v.begin(),v.end());
    for(int i = 0;i<q;i++){
        cin >> x;
        int up = upper_bound(v.begin(),v.end(),x) - v.begin();
        int down = lower_bound(v.begin(),v.end(),x) - v.begin();
        cout << up << " " << down << '\n';
    /*    if (up==down){
            if (up==n || up==0)
                cout << -1 << "\n";
            else
                cout << v[up] - v[down-1] << "\n";
        }
        else{
            if (up==n || down==0){
                cout << -1 << "\n";
            }
            else{
                cout << v[up] - v[down-1] << "\n";
            }
        }
        */
    }
    return 0;
}
