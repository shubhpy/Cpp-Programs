#include<iostream>

using namespace std;

int main(){
    long long int n;
    cin >> n;
    string h;
    int b,a;
    bool ans = false;
    for(int i=0;i<n;i++){
        cin >> h >> b >> a;
        if (b>=2400 && a>b){
            ans = true;
        }
    }

    if (ans){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}

