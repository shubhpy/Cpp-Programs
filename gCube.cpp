#include<iostream>
#include<vector>
#include<math.h>
#include <iomanip>
#include<cstdio>

using namespace std;

int main(){

    int T,a,L,R,M,N,i,D;
    cin >> T;
    for(i=0;i<T;i++){
        vector<long long int> vect;
        cin >> N >> M ;
        for(int j=0;j<N;j++){
            cin>>a;
            vect.push_back(a);
        }
        cout << "Case #" << i+1 <<":"<< "\n";
        for(int k=0;k<M;k++){
            cin >> L >> R;
            D = R-L+1;
            double p= 1;
            for(int o=L;o<R+1;o++){
                p = p*pow(vect[o],1.0/D);
            }
            printf("%.9f",p);
            cout << "\n";
        }
        vect.clear();
    }

    }
