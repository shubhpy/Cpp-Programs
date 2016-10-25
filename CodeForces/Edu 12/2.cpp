

#include<iostream>
#include<vector>

using namespace std;

int main(){

    freopen("2CF.txt","r",stdin);
    int n,m,k;
    int c;
    cin >> n >> m >>k;
    vector<int> v(k);
    vector<int> pos(k);
    for(int i=0;i<k;i++){
        cin >> v[i];
        pos[i] = i+1;
    }



    long long int ans = 0;
    int a;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a;
            for(int p=0;p<k;p++){
                if (v[p]==a){
                    ans+=pos[p];
                    pos[p] = 1;
                    p=k;
                    cout << ans << "\n";
                }
                else{
                    pos[p]++;
                }
            }
        }
    }

    cout << ans;


    return 0;
}

