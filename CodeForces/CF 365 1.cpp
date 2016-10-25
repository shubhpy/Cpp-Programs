
#include<iostream>

using namespace std;

int main(){

    int n,m,c;
    cin >>  n;

    long long int summ = 0;
    long long int sumc = 0;

    for(int i=0;i<n;i++){
        cin >> m >> c;
        if (m>c)
            summ+=m;
        else if (m<c)
            sumc+=c;

    }

    if (summ>sumc){
        cout << "Mishka";
    }
    else if (summ<sumc){
        cout << "Chris";
    }
    else{
        cout << "Friendship is magic!^^";
    }


}
