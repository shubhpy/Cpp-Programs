// C++ program to find out whether a given graph is Bipartite or not
#include <iostream>
#include <queue>
using namespace std;

// This function returns true if graph G[V][V] is Bipartite, else false
bool isBipartite(vector<long long int> G[], long long int src,long long int V)
{
    // Create a color array to store colors assigned to all veritces. Vertex
    // number is used as index in this array. The value '-1' of  colorArr[i]
    // is used to indicate that no color is assigned to vertex 'i'.  The value
    // 1 is used to indicate first color is assigned and value 0 indicates
    // second color is assigned.
    long long int colorArr[V];
    for (long long int i = 0; i < V; ++i)
        colorArr[i] = -1;

    // Assign first color to source
    colorArr[src] = 1;

    // Create a queue (FIFO) of vertex numbers and enqueue source vertex
    // for BFS traversal
    queue <long long int> q;
    q.push(src);

    // Run while there are vertices in queue (Similar to BFS)
    while (!q.empty())
    {
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
        long long int u = q.front();
        q.pop();

         // Find all non-colored adjacent vertices
        for (long long int j = 0; j < G[u].size(); ++j)
        {
            // An edge from u to v exists and destination v is not colored
            long long int v = G[u][j];
            if (colorArr[v] == -1)
            {
                // Assign alternate color to this adjacent v of u
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }

            //  An edge from u to v exists and destination v is colored with
            // same color as u
            else if (colorArr[v] == colorArr[u])
                return false;
        }
    }

    // If we reach here, then all adjacent vertices can be colored with
    // alternate color
    long long int c0 = 0;
    long long int c1 = 0;
    for(int i=0;i<V;i++)
    {
        if (colorArr[i]==0){
            c0++;
        }
        else{
            c1++;
        }
    }

    cout <<  c1 << "\n";
    for(int i=0;i<V;i++)
    {
        if (colorArr[i]!=0){
            cout << i+1 << " " ;
        }
    }

    cout << "\n" << c0 << "\n";

    for(int i=0;i<V;i++)
    {
        if (colorArr[i]==0){
            cout << i+1 << " " ;
        }
    }


    return true;
}

// Driver program to test above function
int main()
{

    long long int V,E,u,v;
    cin >> V >> E;
    vector<long long int>G[V];

    for(long long int i=0;i<E;i++){
        cin >> u >> v;
        G[u-1].push_back(v-1);
        G[v-1].push_back(u-1);
    }

    if (!isBipartite(G,u-1,V)){
        cout << -1;
    }
    return 0;
}
