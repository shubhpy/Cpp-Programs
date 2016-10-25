#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;

long long min_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int siz=a.size();

  for (int i = 0; i < siz; ++i) {
      std::cout << a[i] << ' ';
  }
  std::cout << "\n";

  for (int i = 0; i < siz; ++i) {
      std::cout << b[i] << ' ';
      }


  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += a[i] * b[siz-1-i];
  }
  return result;
}

int main() {
    int icount=0;
    while (true) {
    int n = rand() % 10 + 2;
    std::cout << n << "\n";
    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
      a.push_back(rand() % 10);
    }
    for (int i = 0; i < n; ++i) {
      std::cout << a[i] << ' ';
    }
    std::cout << "\n";
    for (int i = 0; i < n; ++i) {
      b.push_back(rand() % 10);
    }
    for (int i = 0; i < n; ++i) {
      std::cout << b[i] << ' ';
    }
    std::cout << "\n";
    std::cout << min_dot_product(a, b) << std::endl;
    icount+=1;
    if(icount==5){
    break;}
  }
  /*size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << min_dot_product(a, b) << std::endl;
  */
}
