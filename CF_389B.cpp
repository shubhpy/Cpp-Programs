
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> vect(n);
    for(int i=0;i<n;i++){
        cin >> vect[i];
        }

    bool match = true;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (match){
                if (vect[i][j] =='#'){
                        if (i+1 < n && j+1 < n && j-1 >= 0 && i+2 < n){
                            if (vect[i+1][j]=='#' && vect[i+1][j-1]=='#' && vect[i+1][j+1]=='#' && vect[i+2][j]=='#'){
                                vect[i+1][j]='.';
                                vect[i+1][j-1]='.';
                                vect[i+1][j+1]='.';
                                vect[i+2][j]='.';
                                vect[i][j] ='.';
                            }
                            else{
                                match = false;
                            }
                }
                else{
                    match = false;
                }
                }
            }
            else{
                break;
            }
        }
    }

    if (match ==false){
        cout << "NO";
    }
    else{
        cout << "YES";
    }
    }
