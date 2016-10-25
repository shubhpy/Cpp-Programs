#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
#define LL long long int

int main() {
    LL n;
    cin >> n;
    vector<LL> vect;
    string dir;
    cin >> dir;
    LL a,b;
    cin >> a;
    for(int i=1;i<n;i++){
        if (dir[i]=='L' && dir[i-1]=='R'){
            cin >> b;
            vect.push_back(b-a);
        }
        else{
            cin >> a;
        }
    }


    if (vect.size()!=0){
        auto p = min_element(vect.begin(),vect.end());
        cout << (*p)/2;
        }
    else{
        cout << -1;
    }
    return 0;
}

