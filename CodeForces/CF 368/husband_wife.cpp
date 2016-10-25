#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define LL long long int

int main() {
    int N;
    cin >> N;
    vector<LL> v(N);
    v[0]=1;
    v[1]=2;
    for(int i=2;i<N;i++){
        int s = (i*(i+1))/2 + 1;
        v[i] = s+v[i-1] - 1;
    }

    cout << v[N-1];
    return 0;

}
