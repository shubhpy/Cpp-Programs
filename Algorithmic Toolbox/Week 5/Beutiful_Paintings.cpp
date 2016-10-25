#include <iostream>


int maxTime(int n,int m) {

    int count=0;

    while(n!=0 && m!=0){
    if (n==1 && m==1){
        break;
        }
    else if (n<=m){
        n+=1;
        m-=2;
        count+=1;
    }
    else if (n>m){
        m+=1;
        n-=2;
        count+=1;
    }

    }

    return count;

    }

int main() {
  int n,m;
  std::cin >> n >> m;
  std::cout << maxTime(n,m);
}
