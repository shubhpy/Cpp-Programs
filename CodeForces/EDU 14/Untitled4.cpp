#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define LL long long int

int main(){
    LL a1,b1,a2,b2,L,R;
    cin >> a1 >> b1 >> a2 >> b2 >> L >> R;
    bool notf = false;
    LL i;
    for(i=L;i<=R;i++){
        if ((((i-b1)/a1)>=0 && ((i-b1)%a1)==0) && (((i-b2)/a2)>=0 && ((i-b2)%a2)==0)){
            notf = true;
            break;
        }
    }
    if (notf){
            cout <<  (R-i)/(a1*a2) + 1;
    }
    else{
        cout << 0;
    }

    return 0;
    }
