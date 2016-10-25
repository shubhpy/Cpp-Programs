
#include<iostream>
#include<vector>

using namespace std;

int main(){
    string s;
    cin >> s;

    char p = s[0];
    int count = 0;
    string a= "";
    string u = "";
    u = u+char((int)s[0] + (int)'A' - (int)'a');
    for(int i=1;i<s.length();i++){
        u = u + char((int)s[i] + (int)'A' - (int)'a');
        if (s[i]==p){
            count++;
        }
        else{
            if (count!=0)
                a = a+p + (char)(count+(int)'1');
            else
                a = a+p;
            count = 0;
            p = s[i];
        }
    }
    if (count!=0)
        a = a+p + (char)(count+(int)'1');
    else
        a = a+p;

    cout << a << "\n";
    cout << u << "\n";



return 0;
    }
