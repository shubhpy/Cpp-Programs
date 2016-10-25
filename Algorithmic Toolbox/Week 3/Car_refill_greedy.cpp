#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int minRefills(vector<int>& x,int n, int L){

    int lastRefill_at =  0;
    int currentPoint_at = 0;
    int noRefills = 0;

    while (currentPoint_at<=n){
    lastRefill_at = currentPoint_at;
    cout << x[lastRefill_at] << "\n";
    while(currentPoint_at<=n && x[currentPoint_at+1]-x[lastRefill_at]<=L){
        currentPoint_at++;
        }

    if (currentPoint_at<=n){
        noRefills++;
        }
    }

    return noRefills;
}


int main() {
    int n;
    int L;
    cin >> n >> L;
    vector<int> x(n+1);
    for(int i=0;i<n;i++){
        cin >> x[i];
    }

    cout << minRefills(x,n,L);


    return 0;
}
