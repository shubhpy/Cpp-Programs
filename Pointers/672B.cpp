#include<iostream>
#include<string.h>
#include <vector>

using namespace std;

int main(){
    string s;
    int n;
    cin>> n;
    cin >> s;
    int count=0;
    vector<int> a(300);

    for(int i=0;i<n;i++){
        a[(int) s[i]]+=1;
    }

    for (int i=0;i<300;i++){
        if(a[i]!=0){
        count+=1;}
    }

    int to_change =n- count;

    if (to_change<=26-count){
    cout<<to_change;
    }
    else{
    cout<<-1;}


}
