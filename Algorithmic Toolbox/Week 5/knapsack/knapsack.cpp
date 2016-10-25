#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

void optimal_weight(int W, const vector<int> &w) {

  int siz=w.size();
  int value[W][siz];
  for (int i=0;i<=W;i++){
    for (int j=0;j<=siz;j++){
        value[i][j]=0;
        }
    }

    int val;
    for (int i=1;i<=siz;i++){
        for (int j=1;j<=W;j++){
            value[j][i] = value[j][i-1];
            if (w[i-1]<=j)
            {
            val = value[j-w[i-1]][i-1] + w[i-1];
            if (value[j][i]<val){
                value[j][i]=val;
                }
            }
        }
    }
/*    for (int i=0;i<=W;i++){
        for (int j=0;j<=siz;j++){
            std::cout << value[i][j] << " ";
            }
            std::cout << " \n";
            }
            */

            std::cout << value[W][siz];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  optimal_weight(W, w);
}
