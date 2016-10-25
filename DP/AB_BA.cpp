#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;


int main(){

    string s;
    cin >> s;
    int firstAB = -1;
    int lastBA = -1;
    int firstBA = -1;
    int lastAB = -1;

    for(int i = 0;i<s.length()-1;i++){
        if (s[i]=='A' && firstAB==-1){
            if (s[i+1]=='B'){
                firstAB = i+1;
            }
        }

        if (s[i]=='B' && firstBA==-1){
            if (s[i+1]=='A'){
                firstBA = i+1;
            }
        }

        if (firstAB!=-1 && firstBA!=-1){
            break;
        }
    }

    for(int i =s.length()-1;i>0;i--){
        if (s[i]=='A' && lastBA==-1){
            if (s[i-1]=='B'){
                lastBA = i-1;
            }
        }

        if (s[i]=='B' && lastAB==-1){
            if (s[i-1]=='A'){
                lastAB = i-1;
            }
        }

        if (lastAB!=-1 && lastBA!=-1){
            break;
        }
    }

    if (firstAB==-1)
        cout << "NO";
    else if (firstBA==-1)
        cout << "NO";
    else if (firstAB < lastBA)
        cout << "YES";
    else if (firstBA < lastAB)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
