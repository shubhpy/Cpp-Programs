#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::cout;
using std::cin;

double get_optimal_value(int n,int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  vector<double> valuesByweights(n);
  for(int i=0;i<n;i++){
    valuesByweights[i] = (double)values[i] / weights[i];
    }

    std::vector<int> y(valuesByweights.size());
    std::size_t nn(0);
    std::generate(std::begin(y), std::end(y), [&]{ return nn++; });

    std::sort(  std::begin(y),
                std::end(y),
                [&](double i1, double i2) { return valuesByweights[i1] < valuesByweights[i2]; } );

    for(int j=0;j<n;j++){
        if (capacity>=weights[y[n-1-j]]){
            capacity-=weights[y[n-1-j]];
            value+=values[y[n-1-j]];
            }
        else{
            value+=valuesByweights[y[n-1-j]]*capacity;
            capacity=0;
            }
        }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(n,capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
