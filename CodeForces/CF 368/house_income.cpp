

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define LL long long int

int main() {
    LL T;
    cin >> T;
    vector<LL> v(T);
    LL n;
    cin >> v[0];
    printf("%.2f ",(float)v[0]);
    for(int t=1;t<T;t++){
        cin >> n;
        int i;
        bool f= false;
        for(i=0;i<t;i++){
            if (v[i]<=n){
                for(int j = t;j>i;j--){
                    v[j]=v[j-1];
                }
                v[i]=n;
                f = true;
                break;
            }
        }
        if (!f){
            v[t]=n;
        }

        if (t%2==0){
            printf("%.2f ",(float)v[t/2]);
        }
        else{
            printf("%.2f ",(float)(v[t/2] + v[(t/2)+1])/2);
        }

    }
    return 0;

}
