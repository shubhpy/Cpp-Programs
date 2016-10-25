
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
    int n,d;
    cin >> n >> d;
    string s;
    int mx = 0;
    int count = 0;
    bool zero = false;
    for(int i=0;i<d;i++){
        zero = false;
        cin >> s;
        for(int j=0;j<n;j++){
            if (s[j]=='0'){
                zero = true;
                j=n;
            }
        }
        if (zero){
            count++;
            mx=max(count,mx);
        }
        else{
            count = 0;
        }
    }

    cout << mx;

    return 0;
}
