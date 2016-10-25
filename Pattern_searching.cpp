
#include<iostream>

using namespace std;

int main(){
    string txt =  "THIS IS A TEST TEXT";
    string pat = "TEST";
    //cin >> txt;
    //cin >> pat;
    bool done;

    for(int i=0;i<txt.length() - pat.length();i++){
        if (txt[i]==pat[0]){
                done  = false;
            for(int j=1;j<pat.length() && !done;j++){
                if (txt[i+j] != pat[j]){
                    done = true;
                }
            }
        if (!done){
            cout <<  "pattern found at index " << i << "\n";
        }
        }
    }

    return 0;
    }
