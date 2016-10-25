#include <iostream>
#include <vector>
#include<climits>
using std::vector;

int dpchange(int x) {
    vector<int> minCoins(x+1,0);

    vector<int> Coins = {2,3,5,6};
    int NumCoins;
    for (int m=1;m<=x;m++){
        minCoins[m]=INT_MAX;
        for(int i=0;i<4;i++){
            if (m>=Coins[i]){
                NumCoins = minCoins[m-Coins[i]] +1 ;
                if (NumCoins<minCoins[m]){
                    minCoins[m]=NumCoins;
                    }
                }
        }
    }
    for(int i=1;i<=x;i++){
    std::cout << i << " " << minCoins[i] << '\n';
}
    std::cout << "\n";
    return minCoins[x];
}

int main() {
  int n;
  int x;
  std::cin >> n;
  for(int i=1;i<n;i++){
  std::cin >> x;
  std::cout << dpchange(x) << '\n';
}
}

/*
067.12403en007
20092011
primitive_calci(n);
  std::cout << optimal_weight(W, w) << '\n';
*/
