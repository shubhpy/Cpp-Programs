//#include<iostream>
//#include<vector>
#include <bits/stdc++.h>

using namespace std;

struct ListNode{

    int VertexNum;
    struct ListNode* next;

};

struct ArrayList{

    struct ListNode* head;

};

struct Graph{

    int V;
    int E;
    struct ArrayList* array;

};

struct ListNode* newAdjListNode(int val)
{
    struct ListNode* newNode =
            (struct ListNode*) malloc(sizeof(struct ListNode));
    newNode->VertexNum = val;
    newNode->next = NULL;
    return newNode;
}


struct Graph* AdjList(int v){

  struct ListNode* temp;
  struct Graph* G = (struct Graph*) malloc(sizeof(struct Graph));

  G->V = v;
  G->E = 0;
  G->array = (struct ArrayList*) malloc((G->V) * sizeof(struct ArrayList));

  for(int i=0;i< G->V; i++){
        G->array[i].head = NULL;
  }

  return G;

}


void addEdge(struct Graph* G,int a, int b){
    //G->E ++;
    struct ListNode* temp = newAdjListNode(b);
    temp->next = G->array[a].head;
     G->array[a].head = temp;
/*
    temp = newAdjListNode(a);
    temp->next = G->array[b].head;
     G->array[b].head = temp;
*/
}


 void Explore(vector<bool>& visited,struct Graph* G,int s){

    visited[s] = true;
    cout << s << " ";
    struct ListNode* pCrawl = G->array[s].head;
    while (pCrawl)
        {
            if (!visited[pCrawl->VertexNum]){
                //cout << pCrawl->VertexNum << " ";
                Explore(visited,G,pCrawl->VertexNum);
            }
            pCrawl = pCrawl->next;
        }
    return;

    }


void DFS(vector<bool>& visited,struct Graph* G,int s){
        for (int v = s; v < G->V; ++v)
            {
                if (!visited[v]){
                    Explore(visited,G,v);
                }
            }

        for (int v = 0; v < s; ++v)
            {
                if (!visited[v]){
                    Explore(visited,G,v);
                }
            }
        return;
    }

void printGraph(struct Graph* graph){

    for (int v = 0; v < graph->V; ++v)
    {
        struct ListNode* pCrawl = graph->array[v].head;
        printf("\n arrayacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            cout << "-> " << pCrawl->VertexNum << " " ;
            pCrawl = pCrawl->next;
        }
        cout << "\n";
    }
    }

int main()
{
    struct Graph* graph  = AdjList(4);
        addEdge(graph, 2, 3);
    //addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);

	printGraph(graph);

    vector<bool> visited(graph->V);
    for(int i=0;i<graph->V;i++){
        visited[i] = false;
    }

    int s = 2;
    DFS(visited,graph,s);

  return 0;
}
/*
Just one problem
It does not keep the order of the list as provided but just opposite of that has to
be.

so we may want to get the edges reverse of the input.
*/

/*
0 1
0 2
1 2
2 0
2 3
3 3
*/
