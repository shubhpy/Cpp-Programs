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

#define fi first
#define se second
#define LL long long int


bool sorted(vector<pair<long long int, int> >& vect,LL n){
    for(int i=1;i<n;i++){
        if (vect[i].fi!=vect[i-1].fi + 1){
            return false;
        }
    }
    return true;
}

int main(){
    int T;
    cin >> T;
    long long int n;
    for(int a0 = 0; a0 < T; a0++){
        cin >> n;
        vector<pair<long long int, int> > vect(n);
        for(int i=0;i<n;i++){
            cin >> vect[i].fi;
            vect[i].se = 2;
        }

       LL count = 0;
       bool hmm  = true;
       bool chaos = false;
        while(hmm){
       for(int i=1;i<n;i++){
           if (vect[i].fi < vect[i-1].fi){
               if (vect[i-1].se>0){
                   LL  temp ;
                   temp = vect[i].fi;
                   vect[i].fi  = vect[i-1].fi;
                   vect[i-1].fi = temp;
                   int num;
                   num  = vect[i-1].se;
                   vect[i-1].se = vect[i].se;
                   vect[i].se = num-1;
                   count++;
               }
               else{
                   hmm  = false;
                   chaos  = true;
                   i=n;
               }
           }
       }

      if (hmm==true){
      if(sorted(vect,n)){
          hmm  = false;
            }
        }
       }

       if (chaos){
           cout << "Too chaotic\n";
       }
        else{
            cout << count << "\n";
        }
    }
    return 0;
}
