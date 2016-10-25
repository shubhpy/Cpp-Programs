// C++ program to print DFS traversal for a given given graph
#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void addEdge(vector<int> g[],int v, int w)
{
    g[v].push_back(w);// Add w to v’s list.
    //g[w-1].push_back(v-1);
}

// The function to do DFS traversal. It uses recursive DFSUtil()
void DFS(int s,vector<int> g[],vector<bool>& vis)
{
    vis[s] = true;
    cout << s+1 << " ";

    // Recur for all the vertices adjacent to this vertex
    for(int i = 0 ; i < g[s].size(); ++i)
        if(!vis[g[s][i]])
            DFS(g[s][i] ,g, vis);
}

void BFS(int s,vector<int> g[],vector<bool>& vis)
{
    vis[s] = true;

    queue<int> q;
    q.push(s);

    int n;
    while(!q.empty()){
        n = q.front();
        q.pop();
        cout << n+1 << " ";
        for(int i = 0 ; i < g[n].size(); ++i)
            if(!vis[g[n][i]]){
                vis[g[n][i]] = true;
                q.push(g[n][i]);
            }
    }
}

int main()
{
    // Create a graph given in the above diagram
    int V = 4;    // No. of vertices
    vector<int> g[V];
    addEdge(g,0, 1);
    addEdge(g,0, 2);
    addEdge(g,1, 2);
    addEdge(g,2, 0);
    addEdge(g,2, 3);
    addEdge(g,3, 3);



    cout << "Following is Depth First Traversal\n";
    int s = 0;
    vector<bool> vis(V);
    for(int i=0;i<V;i++){
        vis[i] = false;
    }

    DFS(s, g, vis);
        cout << "\n";

    for(int i=0;i<V;i++){
        vis[i] = false;
    }

    BFS(s, g, vis);
    return 0;
}
