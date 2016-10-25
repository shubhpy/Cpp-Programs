#include <functional>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
#include<climits>
using namespace std;
#define LL long long int

struct Edge
{
    int src, dest, weight;
};

// a structure to represent a connected, directed and
// weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;
    // graph is represented as an array of edges.
    struct Edge* edge;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
    struct Graph* graph = (struct Graph*) malloc( sizeof(struct Graph) );
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc( graph->E * sizeof( struct Edge ) );
    return graph;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        LL N,M;
        cin >> N >> M;
        int V = N;  // Number of vertices in graph
        int E = M;  // Number of edges in graph
        struct Graph* graph = createGraph(V, E);
        int s,d,w,S;
        for(int i=0;i<M;i++){
            cin >> s >> d >> w;
            graph->edge[i].src = s;
            graph->edge[i].dest = d;
            graph->edge[i].weight =  w;
        }

        cin >> S;
        vector<int> dist(V);

        for (int i = 0; i < V; i++)
            dist[i]   = INT_MAX;
        dist[S] = 0;

        for (int i = 1; i <= V-1; i++){
            for (int j = 0; j < E; j++){
                int u = graph->edge[j].src;
                int v = graph->edge[j].dest;
                int weight = graph->edge[j].weight;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                    dist[v] = dist[u] + weight;
                    }
                }

        // Step 3: check for negative-weight cycles.  The above step
        // guarantees shortest distances if graph doesn't contain
        // negative weight cycle.  If we get a shorter path, then there
        // is a cycle.
        for (int i = 0; i < E; i++)
        {
            int u = graph->edge[i].src;
            int v = graph->edge[i].dest;
            int weight = graph->edge[i].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                printf("Graph contains negative weight cycle");
        }

        cout  << "Vertex Distance from Source  " << S <<  " \n";
        for (int i = 0; i < n; ++i)
            cout << i << "  "  << dist[i]);
    }
}
