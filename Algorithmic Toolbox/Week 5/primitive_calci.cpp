#include <iostream>
#include <vector>
#include<cmath>
#include <algorithm>

using std::vector;
using std::min;

int primitive_calci(int x) {
    vector<int> minCoins(x+1);
    for(int i=0;i<=x;i++){
        minCoins[i] = 0;
        }
        minCoins[1]=1;
        minCoins[2]=1;
    int Num;
    int i1,i2,i3;
    for (int m=3;m<=x;m++){
        i1=minCoins[m-1];
        if (m % 2 == 0) {
            i2=minCoins[m/2];
            if (m % 3 == 0){
            i3=minCoins[m/3];
                minCoins[m] = std::min(std::min(i1,i2),i3);
                for(int k=m-1;k>=m/3;k++){
                    if (minCoins[k]==minCoins[m]){
                        std::cout<<  k << " ";
                        break;
                        }
                    }
                }
            else{
                i2=minCoins[m/2];
                minCoins[m] = std::min(i1,i2);
                for(int k=m-1;k>=m/2;k++){
                    if (minCoins[k]==minCoins[m]){
                        std::cout<<  k << " ";
                        break;
                        }
                    }
            }
        }
        else if (m % 3 == 0){
            i3=minCoins[m/3];
            minCoins[m] = std::min(i1,i3);
            for(int k=m-1;k>=m/3;k++){
                    if (minCoins[k]==minCoins[m]){
                        std::cout<<  k << " ";
                        break;
                        }
                    }
        }
        else{
        minCoins[m] = i1;
        for(int k=m-1;k>=m-1;k++){
            if (minCoins[k]==minCoins[m]){
                std::cout<<  k << " ";
                    break;
                }
            }
        }
        if (m>=4){
        minCoins[m]+=1;
        }
        }
        std::cout << "\n";
    std::cout << minCoins[x]<< "\n";
    return 0;

}
int main() {
  int n;
  std::cin >> n;
  primitive_calci(n);

}
