#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    int n;
    cin >>  n;

    vector<int> v(n);

    for(int i = 0;i<n;i++){
        cin >> v[i];
    }

    int last = 1;
    int ans = 1;
    for(int i = 1;i<n;i++){
        if (v[i-1]<=v[i]){
            last++;
            ans = max(ans,last);
        }
        else{
            last = 1;
        }
    }

    cout << ans;

    return 0;

}
