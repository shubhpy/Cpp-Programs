#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n,m;
    cin >>  n >> m;

    vector<int> v(m);

    for(int i = 0;i<m;i++){
        cin >> v[i];
    }

    sort(v.begin(),v.end());

    int ans = 1000;
    for(int i = 0;i<=m-n;i++){
        ans = min(ans,v[i+n-1] - v[i]);
    }

    cout << ans;


    return 0;

}
