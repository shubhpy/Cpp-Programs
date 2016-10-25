#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    int n;
    cin >> n;
    int c=1;
    for(int i=n-1;i>-1;i--){
        for(int j=0;j<i;j++){
            cout << " ";
        }
        for(int k=0;k<c;k++){
            cout<< "#";
        }
        cout << "\n";
        c++;
    }
    return 0;
}
