#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

    freopen("bersu.txt","r",stdin);
    int nb,ng;
    cin >>  nb;
    vector<int> B(nb);

    for(int i = 0;i<nb;i++){
        cin >> B[i];
    }
    cin >>  ng;
    vector<int> G(ng);

    for(int i = 0;i<ng;i++){
        cin >> G[i];
    }

    sort(B.begin(),B.end());
    sort(G.begin(),G.end());

    int gs = 0;
    int count = 0;
    int i = 0;
    int j = 0;
    while(i!=nb && j!=ng){
        if (abs(B[i]-G[j]) <=1){
            count++;
            i++;
            j++;
        }
        else if (B[i]>G[j]){
            j++;
        }
        else{
            i++;
        }
    }
    cout << count;
    return 0;
}



