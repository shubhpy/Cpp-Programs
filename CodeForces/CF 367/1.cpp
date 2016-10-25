#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<cmath>

using namespace std;
#define LL long long int

int main(){
        int i,j,k,l,m,n,x,y,z;
        int a,b,t;

        cin >> a >> b;

        cin >> t;
        double mn= INT_MAX;
        for(i=0;i<t;i++){
            cin >> x >> y >> z;

            mn = min(sqrt(pow(x-a,2) + pow(y-b,2))/z , mn);
        }

        printf("%f",mn);
        return 0;
    }
