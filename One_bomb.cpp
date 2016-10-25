#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
#define LL long long int

int main() {
    int n,m;
    cin >> n >> m;
    vector<string> vect(n);
    for(int i=0;i<n;i++){
        cin >> vect[i];
    }

    vector<int> vm(1001,0);
    vector<int> vn(1001,0);
    int x,y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (vect[i][j]=='*'){
                    vn[i]++;
                    vm[j]++;
            }
        }
    }

    int f;
    int countn = 0;
    int countm = 0;
    for(int i=0;i<1001;i++){
        if (vn[i]!=0){
            f = count(vn.begin(),vn.end(),vn[i]);
            if (f>1){
                x = i;
                countn++;
            }
        }
        if (vm[i]!=0){
            f = count(vm.begin(),vm.end(),vm[i]);
            if (f>1){
                y = i;
                countm++;
            }
        }

    }

    if (countn>1 || countm>1){
        cout << "NO";
    }
    else{
        cout << "YES\n";
        cout << x+1 << " " << y+1;
    }


    return 0;
}


