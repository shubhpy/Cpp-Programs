#include<iostream>
#include<queue>

using namespace std;
int fun(int i,int j){
    if(i==j){
    return 1;
    }
    else if(i>j){
        return fun(i-j,j)+1;
    }
    else{
    return fun(i,j-i)+1;
    }
}

int main(){

    queue<int> q;
    q.
    /*
    int M,N,J,Q;
    cin >> M >> N >> J >> Q;
    int count=0;
    for(int i=M;i<=N;i++){
        for(int j=J;j<=Q;j++){
            count+=fun(i,j);
            }
        }

    cout << count;
    */

}
