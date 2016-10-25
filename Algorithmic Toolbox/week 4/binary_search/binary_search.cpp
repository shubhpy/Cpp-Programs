#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

using std::vector;

int binary_Search(vector<int> &x,int low,int high, int key) {
  if (high<low){
        return -1;
        }
    double mid = std::floor(low  + (high-low)/2);

    if (x[mid]==key){
        return mid;
        }
    else if( key < x[mid]){
        return binary_Search(x,low,mid-1,key);
        }
    else{
        return binary_Search(x,mid+1,high,key);
        }
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_Search(a,0,n,b[i]) << ' ';
  }
}
