#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long get_fibonaccihuge(int n, int m) {
    vector<long long> numbers(n+1);
    numbers[0]=0;
    numbers[1]=1;
    for (int i = 2; i <= n; i++)
        numbers[i]=numbers[i-1]+numbers[i-2];
  return numbers[n]%m;
  std::cout << get_fibonaccihuge(n, m) << '\n';
}

int Find_the_Pattern (int m) {
    vector<long long> numbers(40+1);
    vector<int> pattern(40+1);
    numbers[0]=0;
    pattern[0]=numbers[0]%m;
    numbers[1]=1;
    pattern[1]=numbers[1]%m;
    for (int i = 2; i <= 40; i++){
        numbers[i]=numbers[i-1] + numbers[i-2];
        pattern[i]= numbers[i]%m;
        }
    int temp=1;
    int no_once=1
    while(temp){
        for (int j=1;j<40;j++){




        }


    }

  return 0;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    Find_the_Pattern(m);
}
