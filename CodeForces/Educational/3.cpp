#include<iostream>
#include<vector>
#include<algorithm>
#include <cmath>
using namespace std;
#define LL long long int
#define INF 1000000009

int main(){


    LL C,T;
    cin >> C >> T;
    vector<LL> c(C);
    for(int i=0;i<C;i++){
        cin >> c[i];
    }
    vector<LL> t(T);
    for(int i=0;i<T;i++){
        cin >> t[i];

    }
    LL  max = 0;

    int i = 0;
    int j = 0;
    LL prev = INF;
    LL local_min;
    bool j_over = false;

    for(int k=0;k<C+T;k++){
        if (j==T-1){
            local_min  = abs(t[j] - c[i]);
            if (local_min > max){
                max =  local_min;
            }

            if (i!=C-1){
                i++;
            }
        }

        else if (c[i] < t[j]){
            local_min  = min(abs(t[j] - c[i]) ,abs(c[i] - prev));
            if (local_min > max){
                max =  local_min;
            }

            prev = t[j];
            if (j!=T-1){
                j++;
            }

            if (i!=C-1){
                i++;
            }


        }
        else{
            prev = t[j];
            if (j!=T-1){
                j++;
            }
        }
    }

    cout << max;

    return 0;

}
