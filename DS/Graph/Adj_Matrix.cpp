#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

struct Graph{

    int V;
    int E;
    int** array;

};

struct Graph* AdjMatrix(int v,int e){

  struct Graph* G = (struct Graph*) malloc(sizeof(struct Graph));

  G->V = v;
  G->E = e;

  //G->array = (int**) malloc(G->V *G->V * sizeof(int*));

  G->array = (int**)malloc(G->V * sizeof(int*));
  for(int i=0; i< G->V; i++){
    (G->array)[i] = (int*)malloc(G->V *sizeof(int));
  }

  for(int i=0;i< G->V; i++){
    for(int j=0;j< G->V; j++){
    G->array[i][j] = 0;
        }
  }

    int a,b;
    for(int k=0;k< G->E ;k++){
            cin >> a >> b;
            G->array[a][b] = 1;
            G->array[b][a] = 1;
        }

    return G;
}

int main()
{
    struct Graph* G  = AdjMatrix(5,7);

    for(int i=0;i< G->V; i++){
        for(int j=0;j< G->V; j++){
        cout << G->array[i][j] << " " ;
        }
        cout << "\n";
  }

  return 0;
}

