#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    int N;
    for(int t=0;t<T;t++){
        cin >> N;
        vector<int> v(N);
        long long int sum = 0;
        for(int i=0;i<N;i++){
            cin >> v[i];
            if (v[i]>0)
                sum+=v[i];
        }
        if (sum==0){
            int mx = *max_element(v.begin(),v.end());
            cout << mx << "\n";
        }
        else{
            long long int maxendhere = v[0];
            long long int maxsofar = v[0];
            for(int i=1;i<N;i++){
                maxendhere = max((long long int)v[i],maxendhere+v[i]);
                maxsofar = max(maxendhere,maxsofar);
            }
            cout << maxsofar << "\n";
        }
    }
    return 0;

}
