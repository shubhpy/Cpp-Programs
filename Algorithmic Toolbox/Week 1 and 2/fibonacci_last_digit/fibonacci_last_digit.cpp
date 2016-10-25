#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long get_fibonacci_last_digit(int n)
{
    vector<long long > numbers(n+1);
    numbers[0]=0;
    numbers[1]=1;
    for (int i = 2; i <= n; i++)
        numbers[i]=numbers[i-1]%10+numbers[i-2]%10;
  return numbers[n]%10;
}

int main() {
  int n;
  std::cin >> n;
  long long c = get_fibonacci_last_digit(n);
  std::cout << c << '\n';
}
