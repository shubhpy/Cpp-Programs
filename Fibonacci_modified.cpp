#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int A,B,N;
    cin >> A >> B >> N;
    vector<unsigned long long int> a(N);
    a[0]=A;
    a[1]=B;
    for(int i=2;i<N;i++){
        a[i]=a[i-1]*a[i-1]  + a[i-2];
    }
    cout  << a[N-1];

    return 0;
}
