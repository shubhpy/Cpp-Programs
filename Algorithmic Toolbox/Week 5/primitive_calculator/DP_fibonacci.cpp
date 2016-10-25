#include <iostream>
#include <vector>
using std::vector;
#define MAX 100

vector<int> Num(MAX);

void intialize(){
    for (int i=0;i<MAX;i++){
    Num[i]=0;
        }
}
int dp_fibo(int x) {

    if (Num[x]==0)
        {
        if (x==0){
            Num[x]=0;
            }
        else if (x==1){
            Num[x]=1;
            }
        else{
            Num[x]=dp_fibo(x-1) + dp_fibo(x-2);
            }
        }
    return Num[x];
    }

int main() {
  int n;
  std::cin >> n;
  intialize();
  std::cout << dp_fibo(n);
}
