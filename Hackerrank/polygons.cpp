#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    long long int sum = 0;
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
        sum += a[a_i];
    }

    int mx = *max_element(a.begin(),a.end());
    if (mx < sum-mx){
        cout << 0 ;
    }
    else{
        cout <<  1;
    }

    return 0;
}
