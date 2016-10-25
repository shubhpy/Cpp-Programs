#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define LL long long int

int main(){
    LL n,a;
    //cin >> n >> a;
    //vector<LL> v(n);

    double f=  0;

    for(int i=1;i<100000;i++){
            //cout << (float)(9+ 2*i)/(2*i) << "\n";
            f += (float)(9+ 2*i)/(2*i);
    }
    cout <<  f/100000;
    return 0;
    }


