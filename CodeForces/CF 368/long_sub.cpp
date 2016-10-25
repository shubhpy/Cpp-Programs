
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin >> T;
    string s;
    for(int t=0;t<T;t++){
        cin >> s;
        int l = s.length();
        vector<int> v(26,-1);
        for(int i=0;i<l;i++){
            if (v[(int)s[i] - (int)'a']==-1){
                v[(int)s[i] - (int)'a'] = i;
                }
        }
        //for(int i=0;i<26;i++){
        //        cout << v[i] << " ";
        //}
        //cout << "\n";
        for(int i=0;i<26;i++){
            if (v[i]!=-1){
                for(int j=0;j<l-v[i];j++){
                    cout << s.substr(v[i],j+1) << "\n";
                }
            }
        }
    }
    return 0;

}
