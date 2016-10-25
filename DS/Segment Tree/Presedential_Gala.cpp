#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<climits>
using namespace std;
#define maxn 100005
#define LL long long int

void solve(vector<int> tree[],vector<int> &vis,vector<int> &p,int s,LL &ans,LL sump,int count){
    vector<int>::iterator it;
	for (it=tree[s].begin(); it!=tree[s].end(); it++){
        if (vis[*it]==0){
            vis[*it]=s;
            count++;
        }
    }
    if (count==vis.size()-1){
        //cout << ans << " " << sump << "\n";
        ans = max(ans,sump);

        for (it=tree[s].begin(); it!=tree[s].end(); it++){
            if (vis[*it]==s){
                vis[*it]=0;
                count--;
            }
        }
        return ;
    }

    for(int i = s;i<=vis.size()-1;i++){
        if (vis[i]==0){
            vis[i] = i;
            count++;
            solve(tree,vis,p,i,ans,sump+p[i],count);
            count--;
            vis[i] = 0;
        }
    }

    for (it=tree[s].begin(); it!=tree[s].end(); it++){
        if (vis[*it]==s){
            vis[*it] = 0 ;
            count--;
        }
    }

    return ;
}


int main() {
    freopen("gala.txt","r",stdin);
    int n,m;
    cin >> n >>  m;
    vector<int> p(n+1);
    for(int i = 1;i<n+1;i++){
        cin >> p[i];
    }
    int a,b;
    vector<int> tree[maxn];
    for(int i = 0;i<m;i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<int>  vis(n+1,0);
    int count = 0;
    LL ans = INT_MIN;
    for(int i = 1;i<=n;i++){
        vis[i] = i;
        count++;
        solve(tree,vis,p,i,ans,p[i],count);
        count--;
        vis[i] = 0;
    }

    cout << ans;

    return 0;
}
