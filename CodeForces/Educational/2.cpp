#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define LL long long int

int main(){

    LL N;
    cin >> N;
    vector<LL> v(N);
    for(int i=0;i<N;i++){
        cin >> v[i];
    }

    sort(v.begin(),v.end());

    vector<LL> p(35);
    p[0] = 1;

    for(int i=1;i<35;i++){
        p[i] = p[i-1]*2;
    }

    LL ans = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<35;j++){
            ans += (LL)abs(upper_bound(v.begin() + i + 1,v.end(),p[j] - v[i]) - lower_bound(v.begin()+ i +1,v.end(),p[j] - v[i]));
        }
    }

    cout << ans;

    return 0;
    }
