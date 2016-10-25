#include<iostream>

using namespace std;
#define LL long long int

int main(){

    LL n,b,d;
    cin >> n >> b >> d;
    LL x;
    LL sum = 0;
    LL count = 0;
    for(int i=0;i<n;i++){
        cin >> x;
        if (x<=b){
            sum+=x;
        }
        if (sum>d){
            count++;
            sum= 0;
        }
    }
    cout << count;
    return 0;
    }
