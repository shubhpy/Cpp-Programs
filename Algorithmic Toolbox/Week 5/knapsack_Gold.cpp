#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int siz=w.size();
  int value [W+1][siz+1];
  for (int i=0;i<=siz;i++){
    for (int j=0;j<=W;j++){
        value[i][j]=0;
        }
    }
    int val;
  for (int i=1;i<=siz+1;i++){
    for (int j=1;j<=W;j++){
        value[j][i] = value[j][i-1];
        if (w[i-1]<=j){
            val = value[j-w[i-1]][i-1] + w[i-1];
            if (value[j][i]<val){
                value[j][i]=val;
            }
        }

        }
    }
return value[W][siz];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w);

}
