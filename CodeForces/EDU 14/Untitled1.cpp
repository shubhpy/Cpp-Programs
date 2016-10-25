#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define LL long long int

int main(){
    string s;

    cin >> s;
    char c = s[0];
    char r = s[1];

    if (r== '1' || r=='8'){
        if (c=='a'|| c== 'h'){
            cout << 3;
        }
        else{
            cout << 5;
        }
    }
    else{
        if (c=='a'|| c== 'h'){
            cout << 5;
        }
        else{
            cout << 8;
        }

    }
    return 0;
    }

