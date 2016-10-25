// C++ program to print DFS traversal for a given given graph
#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void addEdge(vector< vector<int> > &g,int v, int w)
{
    g[v-1].push_back(w-1);// Add w to v’s list.
    g[w-1].push_back(v-1);
}

// The function to do DFS traversal. It uses recursive DFSUtil()
void DFS(int s,vector< vector<int> > &g,vector<bool>& vis)
{
    vis[s] = true;
    cout << s+1 << " ";

    // Recur for all the vertices adjacent to this vertex
    vector<int>::iterator i;
    for(i = g[s].begin(); i != g[s].end(); ++i)
        if(!vis[*i])
            DFS(*i, g, vis);
}

void DFS_VISIT(int u,int &t,vector< vector<int> > &g,vector<pair<int,int> > &time,vector<bool>& vis)
{
    t = t+1;
    time[u].first = t;
    vis[u] = true;

    vector<int>::iterator i;
    for(i = g[u].begin(); i != g[u].end(); ++i)
        if(!vis[*i])
            DFS_VISIT(*i,t, g, time,vis);

    t = t+1;
    time[u].second = t;
}



void DFS_TOPO(vector< vector<int> > &g,vector<pair<int,int> > &time,vector<bool>& vis)
{
    int t = 0;

    for(int i = 0;i<5;i++){
        if (!vis[i]){
            DFS_VISIT(i,t,g,time,vis);
        }
    }
}


void BFS(int s,vector< vector<int> > &g,vector<bool>& vis)
{
    vis[s] = true;

    queue<int> q;
    q.push(s);

    int n;
    while(!q.empty()){
        n = q.front();
        q.pop();
        cout << n+1 << " ";
        vector<int>::iterator i;
        for(i = g[n].begin(); i != g[n].end(); ++i)
            if(!vis[*i]){
                vis[*i] = true;
                q.push(*i);
            }
    }
}


int main()
{
    // Create a graph given in the above diagram
    int V = 5;    // No. of vertices
    vector< vector<int> > g(V, vector<int>(V,0));

    addEdge(g,1, 2);
    addEdge(g,1, 3);
    addEdge(g,1, 4);
    addEdge(g,3, 5);
    //addEdge(g,2, 3);
    //addEdge(g,3, 3);



    cout << "Following is Depth First Traversal\n";
    int s = 0;
    vector<bool> vis(V,false);
    vector<pair<int,int> > time(V);

    DFS_TOPO(g,time,vis);

    for(int i = 0;i<V;i++){
        cout << i << " " << time[i].first << " " << time[i].second << " \n";
    }

    //DFS(s, g, vis);
    cout << "\n";

    //for(int i=0;i<V;i++){
    //    vis[i] = false;
    //}

    //BFS(s, g, vis);


    return 0;
}
