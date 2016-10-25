#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

#define LL long long int
#define F first
#define S second

int main(){

    //freopen("2.txt","r",stdin);

    int n ,m;
    cin >>  n >>  m;
    int v[n][m];

    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> v[i][j];
        }
    }

    int temp ;
    int count = 0;
    for(int i =0;i<n;i++){
        for(int j = 0;j<m;j++){
            temp = v[i][j];
            count = 0;
            if (j==0){
                for(int k = 0;k<n;k++){
                    if (v[k][j]==temp){
                        count++;
                    }
                }
                for(int k = 0;k<n;k++){
                    if (v[k][j+1]==temp){
                        count++;
                    }
                }

            }
            else if (j==m-1){
                for(int k = 0;k<n;k++){
                    if (v[k][j]==temp){
                        count++;
                    }
                }
                for(int k = 0;k<n;k++){
                    if (v[k][j-1]==temp){
                        count++;
                    }
                }
            }
            else{
                for(int k = 0;k<n;k++){
                    if (v[k][j]==temp){
                        count++;
                    }
                }
                for(int k = 0;k<n;k++){
                    if (v[k][j-1]==temp){
                        count++;
                    }
                }
                for(int k = 0;k<n;k++){
                    if (v[k][j+1]==temp){
                        count++;
                    }
                }
            }

            if (count!=n){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;

}


