#include <functional>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;
#define LL long long int

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        LL N,M;
        cin >> N >> M;
        int a,b,c,S;
        vector< vector<int> > g((N+1), vector<int>(N+1));
        for(int i=0;i<M;i++){
            cin >> a >> b >> c;
            g[a][b] = c;
            g[b][a] = c;
        }

        vector<LL> dis(N+1,-1);

        cin >> S;

        priority_queue<int> pq;
        dis[S] = 0;
        pq.push(-1*S);

        while(!pq.empty()){
            int s = pq.top();
            pq.pop();
            for(int i=0;i<g[s].size();i++){
                if (dis[g[s][i]]==-1){
                    dis[g[s][i]] = dis[s] + 6;
                    q.push(g[s][i]);
                }
            }
        }

        for(int i=1;i<=N;i++){
            if (i!=S)
                cout << dis[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
