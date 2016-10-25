#include<iostream>

using namespace std;

int main(){

    long int l,k,x;
    long int c = 0;
    cin >> l >> k;

    for(int i = 0;i<l;i++){
        cin >> x;
        if (x%k==0){
            c++;
        }
    }

    cout << c;

    return 0;


}
