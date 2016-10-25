#include<iostream>
#include<vector>
using namespace std;
#define LL long long int
#define MOD 1000000009

LL solve(LL p,LL num){

    if (p<10){
        LL t = 1;
        for(int i=0;i<p;i++){
            t = (num * t)%MOD;
        }
        return t;
        }
    else{
        LL t = 1;
        for(int i=0;i<p%10;i++){
            t = (t * num)%MOD;
        }

        t = t%MOD;

        LL A10  = 1 ;
        for(int i=0;i<10;i++){
            A10 = ( A10 * num)%MOD;
        }
        A10 = A10%MOD;

        return t * solve(p/10,A10);
    }
    }

int main(){
    LL A,B,n,x;

    cin >> A >> B >> n >> x;

    LL ans = 0;
    LL An = solve(n,A);
    //LL An = (An1 * A)%MOD;
    ans  = ans  + (An*x)%MOD;

    ans = ans%MOD;

    //cout << An1 << " " << An << " " << ans << " "<<"\n";

    LL sum ;

    if (A==1){
        sum = 1 ;
    }
    else{
        sum = 1 + (An - A)/(A - 1);
    }

    sum = sum%MOD;

    ans =  ans + (sum*B)%MOD ;

    cout << ans%MOD;


return 0;
}

