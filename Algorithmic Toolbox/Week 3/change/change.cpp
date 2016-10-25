#include <iostream>

int get_change(int n) {

  int coins=0;
  if(n%20!=0){
    coins+=n/20;
    n=n%20;
    if(n%8!=0){
        coins+=n/8;
        n=n%8;
        coins+=n;
        }
        else{
        coins+=n/8;
        }
  }
  else{
    coins+=n/20;
  }

  return coins;
}

int main() {
  int n;
  int x;
  std::cin >> n;
  for(int i=1;i<n;i++){
  std::cin >> x;
  std::cout << get_change(x) << '\n';
}
}
