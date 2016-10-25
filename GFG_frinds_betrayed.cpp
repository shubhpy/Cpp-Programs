#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
#define LL long long int

bool BFS(int s,int se,vector< vector<int> > &G,vector<bool>& vis)
{
    vis[s] = true;

    if (s==se){
        return true;
    }

    queue<int> q;
    q.push(s);

    int n;
    while(!q.empty()){
        n = q.front();
        q.pop();
        //cout << n+1 << " ";
        vector<int>::iterator i;
        for(i = G[n].begin(); i != G[n].end(); ++i)
            if(!vis[*i]){
                if (*i==se){
                    return true;
                }
                else{
                    vis[*i] = true;
                    q.push(*i);
                }
            }
    }

    return false;
}

int main(){
    int T,N,Q,a,b;
    cin >> T;
    for(int t=0;t<T;t++){
        cin >> N;

        vector<vector<int> > G(N+1,vector<int>());

        for(int i=0;i<N-1;i++){
            cin >> a >> b;
            G[a].push_back(b);
        }

        cin >> Q;

        for(int i=0;i<Q;i++){
            cin >> a >> b;

            vector<bool> vis(N+1,false);

            if (BFS(a,b,G,vis)){
                cout << a << " ";
            }
            else{
                vector<bool> vis(N+1,false);

                if (BFS(b,a,G,vis)){
                    cout << b << " ";
                }
                else{
                    cout <<  -1 << " ";
                }
            }
        }

    }
    return 0;
    }



