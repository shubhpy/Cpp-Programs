#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define oo 2000000000
#define MOD 1000000007
#define LL long long int
#define PII pair<int,int>
#define DEBUG 0

using namespace std;

int main(){
    int n ,m;
    cin >> n >> m;
    int v[n];
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }

    int count = 0;
    for(int i = 0;i<n-2;i++){
        if (v[i] + v[i+1]<m){
            if (m - v[i] - v[i+1] > m - v[i+1] - v[i+2]){
                if (v[i] < v[i+1]){
                    count += m - v[i+1] - v[i];
                    v[i] = m - v[i+1];
                }
                else{
                    count += m - v[i] - v[i+1];
                    v[i+1] = m - v[i];
                }
            }
            else if (m - v[i] - v[i+1] <= m - v[i+1] - v[i+2]){
                count += m - v[i] - v[i+1];
                v[i+1] = m - v[i];
            }
        }
    }

    if (v[n-1]+v[n-2]<m){
        count += m - v[n-2] - v[n-1];
        v[n-1] = m - v[n-2];
    }

    cout << count << "\n";
    for(int i = 0;i<n;i++){
        cout << v[i] << " ";
    }
    return 0;
    }

