#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int main() {
    int n;
    cin >> n;
    vector<long long> numbers(n+1);
    numbers[0]=0;
    numbers[1]=1;
    for (int i = 2; i <= n; i++)
        numbers[i]=numbers[i-1]+numbers[i-2];

    cout << numbers[n]<< "\n";
    return 0;
}
/*
0 1 1 2 3 5
*/
