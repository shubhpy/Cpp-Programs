#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    long long int N;
    for(int i=0;i<T;i++){
        cin >> N;
        vector<long long int> vect(N);
        for(int j=0;j<N;j++){
            cin >> vect[i];
        }

        if (N % 2 == 0){
            cout << 0;
        }
        else{
            long long int c = vect[0]^vect[N-1];
            cout << c;
        }
        cout << "\n";
    }
    return 0;
}
