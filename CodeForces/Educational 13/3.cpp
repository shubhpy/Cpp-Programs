#include<iostream>
#include<vector>
using namespace std;
#define LL long long int


int main(){
    LL n,a,b,p,q;
    cin >> n >>a >> b >>p >>q;

    LL temp1 = a;
    LL lcm;
    LL temp2 = b;

    if (a>b){
        LL r = temp1%temp2;
        while(r!=0){
            temp1 = temp2;
            temp2 = r;
            r = temp1%temp2;
        }

        lcm = (a*b)/temp2;
    }
    else {
        LL r = temp2%temp1;
        while(r!=0){
            temp2 = temp1;
            temp1 = r;
            r = temp2%temp1;
        }

        lcm = (a*b)/temp1;
    }

    if (p>q){
        cout  << (n/a)*p  + ((n/b) - (n/(lcm)))*q;
    }
    else{
        cout << (n/b)*q  + ((n/a) - (n/(lcm)))*p;
    }


return 0;
}
