#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define LL long long int

int main(){
    string s;
    cin >> s;
    LL T;
    cin >> T;
    vector<int> v(26,0);
    for(int i=0;i<s.length();i++){
        if (v[(int)s[i]- (int)'a'] ==0)
            v[(int)s[i]- (int)'a']=1;
    }

    for(int t=0;t<T;t++){
        string q;
        cin >> q;
        bool done = false;
        for(int i=0;i<q.length();i++){
            if (v[(int)q[i] - (int)'a']==0){
                cout << "No\n";
                done  = true;
                break;
            }
        }
        if (!done){
            cout << "Yes\n";
        }
    }
    return 0;
    }


