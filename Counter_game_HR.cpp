#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >>  T;
    unsigned long long int N;
    for(int i=0;i<T;i++){
        cin >> N;
        int count=0;
        while(N-1 > 0){
            count++;
            if (N && !(N & (N - 1)) == 0){
                N = N/2;
            }
            else{
                N = N - pow(2,floor(log(N)/log(2)));
            }
        }
        cout << count;
    if (count % 2 ==0){
        cout << "Richard" << "\n";
    }
    else{
        cout << "Louise" << "\n";
    }
    }

    return 0;
}
