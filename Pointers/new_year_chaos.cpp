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
    int T;
    cin >> T;
    for(int a0 = 0; a0 < T; a0++){
        int n;
        cin >> n;
        vector<int> q(n);
        for(int q_i = 0;q_i < n;q_i++){
           cin >> q[q_i];
        }
        int a[n][2];
        for(int q_i = 0;q_i < n;q_i++){
          a[q_i][0] = q[q_i];
          a[q_i][1] = 2;
        }
        // your code goes here
        int count=0;
        int temp=0,tmp=0;
        int i=1;
        bool too = false;
        while(i!=n){
        if (a[i][0]-a[i-1][0]<0 && a[i-1][1]>0){
                count++;
                temp=a[i][0];
                a[i][0]=a[i-1][0];
                a[i-1][0]=temp;

                tmp=a[i][1];
                a[i][1]=a[i-1][1];
                a[i-1][1]=tmp;
                a[i][1]-=1;
                if (a[i][1]==-1){
                    too=true;
                    break;
                    }
                i=0;
        }
         i++;
        }
        if(too){
        cout << "Too chaotic";
        }
        else
        {
        cout << count << "\n";
    }
        for(int q_i = 0;q_i < n;q_i++){
            cout << a[q_i][0] << " " << a[q_i][1] << " \n";
        }
    return 0;
}
}
