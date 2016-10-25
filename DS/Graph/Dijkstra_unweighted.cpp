#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
#include <iomanip>
using namespace std;
#define LL long long int



struct Pair {
    int v; // >= 0
    int distv; // 0-59

};

struct ComparePairs{

    bool operator()(Pair& p1, Pair& p2)
    {
       if (p1.distv > p2.distv) return true;
       return false;
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    freopen("input.txt","r",stdin);
	//freopen("out6.txt","w",stdout);
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        LL N,M;
        cin >> N >> M;
        int a,b,S,w;
        vector<pair<int,int> > g[N+1];
        for(int i=0;i<M;i++){
            cin >> a >> b >> w;
            g[a+1].push_back(make_pair(b+1,w));
            g[b+1].push_back(make_pair(a+1,w));
        }

        vector<LL> dis(N+1,-1);
        vector<LL> prev(N+1,-1);

        cin >> S;

        priority_queue<Pair, vector<Pair>, ComparePairs> pq;
        //Pair t[4] = { {3, 40}, {3, 26}, {5, 13}, {5, 20}};

        Pair p = {S,0};

        pq.push(p);

        /*
        while (! pq.empty()) {
           Pair p2 = pq.top();
           cout << setw(3) << p2.v << " " << setw(3) << p2.distv << "\n";
           pq.pop();
        }
        */

        while(!pq.empty()){
            Pair p = pq.top();
            int u = p.v;
            cout << "In while with  " <<  u << "\n";
            int distu = p.distv;
            //pq.pop();
            for(int i=0;i<g[u].size();i++){
                int v = g[u][i].first;
                if (dis[v] > distu + g[u][i].second ){
                    dis[v] = distu + g[u][i].second;
                    prev[v] = u;
                    pq.push((Pair){v,dis[v]});
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
