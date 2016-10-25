
#include<iostream>
#include<vector>
using namespace std;
#define LL long long int

int main(){
    LL N;
    cin >> N;
    vector<LL> v(N);
    for(int i=0;i<N;i++){
        cin >> v[i];
    }

    LL mx = 1;
    LL count = 1;
    for(int i=1;i<N;i++){
        if (v[i] > v[i-1]){
            count++;
            mx = max(mx,count);
        }
        else{
            count =1;
        }
    }

    cout << mx;

    return 0;
    }
