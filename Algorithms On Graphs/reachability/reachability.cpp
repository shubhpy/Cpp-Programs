#include <iostream>
#include <vector>

using namespace std;


void reach(bool &found ,int ver, vector<vector<int> > &adj, int x, int y) {

  if (x!=0 && adj[x][0] ==-1 && found==false){
      adj[x][0]=0;
      for (int i=1;i<ver+1;i++){
          cout << x << " "<< adj[x][i] << " " << y << "\n";
          if (adj[x][i] != y){
             reach(found,ver,adj, adj[x][i], y);
          }
          else{
              found = true;
              //cout << 1 << "\n";
          }
        }
  }
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n+1, vector<int>());
  for (size_t i = 1; i < n+1; i++) {
      adj[i].push_back(-1);
  }
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int x, y;
  std::cin >> x >> y;
  bool found = false;
  reach(found,n,adj, x, y);
  cout << found << "\n";
}
10 10
2 7
4 10
5 9
5 10
4 6
6 7
9 10
1 6
5 8
7 9
9 3


