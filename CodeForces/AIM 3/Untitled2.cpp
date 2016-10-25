#include<iostream>
#include<vector>

using namespace std;
#define LL long long int

int main(){

    string s;

    cin >> s;
    bool charfound=false;
    LL afound = 0;
    LL count = 0;

    vector<char> v(s.length());
    for(int k=0;k<v.size();k++){
            v[k] = s[k];
    }

    for(int i=0;i<s.length();i++){
        if (s[i]=='a'){
            if (charfound==true){
                break;
            }
            else{
                afound=1;
            }
            count++;
        }
        else{
            if (afound==0){
                v[i] = (char)((int)v[i] - 1);
                charfound = true;
            }
            else if (afound==1){
                v[i] = (char)((int)v[i] - 1);
                charfound = true;
            }
        }

    }
    if (count==s.length()){
        for(int k=0;k<v.size()-1;k++){
            cout << v[k];
        }
        cout << 'z';
    }
    else{
        for(int k=0;k<v.size();k++){
            cout << v[k];
        }
    }
    return 0;
    }

