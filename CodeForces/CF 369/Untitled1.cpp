#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define LL long long int

int main(){
    LL T;
    cin >> T;
    vector<string> v(T);
    for(int t=0;t<T;t++){
        cin >> v[t];
    }
    bool f  = false;

    for(int i=0;i<T;i++){
        if (v[i][0] == 'O' && v[i][1]=='O'){
            v[i][0] = '+';
            v[i][1] = '+';
            f = true;
            break;
        }
        else if (v[i][3] == 'O' && v[i][4]=='O'){
            v[i][3] = '+';
            v[i][4] = '+';
            f = true;
            break;
        }
    }

    if (f){
        cout << "YES\n";
        for(int t=0;t<T;t++){
            cout << v[t] << "\n";
        }
    }
    else{
        cout << "NO\n";
    }

    return 0;
    }



