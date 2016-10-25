#include<iostream>
#include<vector>
using namespace std;
#define LL long long int


int main(){
    LL N,K;
    cin >> N >> K;

    cout << ((N/K) + 1 )*K ;

    return 0;

}
