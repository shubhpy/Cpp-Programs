#include<iostream>
//#include<string>
//#include<string.h>
//#include<stdlib.h>

using namespace std;

int main(){

    string s = "1213vdvs2424d424cd2";
    int n;
    string temp = "";
    int sum = 0;
    for(char ch:s){
        if (isdigit(ch)){
            temp+=ch;
        }
        else{
            if (temp!="")
                sum = sum + stoi(temp);
            temp = "";
        }
    }

    cout << sum + stoi(temp);

    return 0;

}
