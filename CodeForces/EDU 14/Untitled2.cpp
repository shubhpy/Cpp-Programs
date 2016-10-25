#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define LL long long int

int main(){
    LL n;
    cin >> n;
    vector<LL> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    sort(v.begin(),v.end());

    if (n%2==0){
        cout << v[(n/2)-1];
    }
    else{
        cout << v[n/2];
    }
    return 0;
    }


