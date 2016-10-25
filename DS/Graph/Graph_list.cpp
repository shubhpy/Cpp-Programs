// C++ program to print DFS traversal for a given given graph
#include<iostream>
#include<vector>
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

int main()
{
    // Create a graph given in the above diagram
    int V = 5;    // No. of vertices
    vector< vector<int> > g(V, vector<int>());
    addEdge(g,1, 2);
    addEdge(g,1, 3);
    addEdge(g,1, 4);
    addEdge(g,3, 5);
    //addEdge(g,2, 3);
    //addEdge(g,3, 3);



    cout << "Following is Depth First Traversal\n";
    int s = 0;
    vector<bool> vis(V);
    for(int i=0;i<V;i++){
        vis[i] = false;
    }
    DFS(s, g, vis);

    return 0;
}
