#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int calc_fib(int n) {
    vector<int> numbers(n+1);
    numbers[0]=0;
    numbers[1]=1;
    for (int i = 2; i <= n; i++)
        numbers[i]=numbers[i-1]+numbers[i-2];
  return numbers[n];
}

int Find_the_Pattern (int n,int m) {
    vector<long long> numbers(n+1);
    vector<int> pattern(n+1);
    numbers[0]=0;
    pattern[0]=numbers[0]%m;
    numbers[1]=1;
    pattern[1]=numbers[1]%m;
    for (int i = 2; i <= n; i++)
        numbers[i]=numbers[i-1] + numbers[i-2];
        std::cout << numbers[i]%m << " ";

  return 0;
}
int main() {
    int n = 0;
    std::cin >> n;

    std::cout << calc_fib(n) << '\n';
    return 0;
}
