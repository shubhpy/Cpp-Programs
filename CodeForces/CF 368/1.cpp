#include<iostream>


using namespace std;


int main(){

    int n,m;
    cin >> n >> m;
    char c;
    bool f = false;
    for(int i=0;i<n*m;i++){
        cin >> c;
        if (c=='C' || c=='M' || c=='Y'){
            f = true;
        }

    }

    if (f){
        cout << "#Color";
    }
    else{
            cout <<  "#Black&White";
    }
    }
