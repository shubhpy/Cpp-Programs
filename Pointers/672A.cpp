#include<iostream>
#include<string.h>

using namespace std;

int main(){
    int n,j;
    int c=0;
    cin >> n;
    char a[n*n];
    for (int i=1;i<=n;i++){
        string s = to_string(i);
        for(j=0;j<s.length();j++){
            a[c+j]=s[j];
        }
        c=c+j;
        if (c==n){
        break;
        }

        }
        cout<<a[n-1];
}
