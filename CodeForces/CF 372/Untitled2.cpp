#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define oo 2000000000
#define MOD 1000000007
#define LL long long int
#define PII pair<int,int>
#define DEBUG 0

using namespace std;

vector<int> check(vector<int> &v, int count){

    int c=0;
    vector<int> ans;
    for(int i = 0;i<26;i++){
        if (v[i]>1){
            return {};
        }
        else if (v[i]==0){
            ans.push_back(i);
            c++;
        }
    }
    if (c==count){
        return ans;
    }
    else{
        return {};
    }
}

int main(){
    freopen("2.txt","r",stdin);
    string s;
    cin >> s;

    if (s.length()<26){
        cout << -1;
        return 0;
    }

    vector<int> v(26,0);
    vector<int> a;

    int count = 0;
    int j;
    bool done = false;
    for(int i = 0;i<=s.length()-26;i++){
        if (i==0){
            count = 0;
            for(j = i;j<26;j++){
                if (s[j]=='?'){
                    count++;
                }
                else{
                    v[(int)s[j]-(int)'A']++;
                }
            }

            a = check(v,count);
            int k = 0;
            if (a.size()!=0){
                done = true;
                for(j = i;j<26;j++){
                    if (s[j]=='?'){
                        s[j] = (char)(a[k] + (int)'A');
                        k++;
                    }
                }
                break;
            }
        }
        else{
            if (s[i-1]=='?'){
                count--;
            }
            else{
                v[(int)s[i-1]-(int)'A']--;
            }

            if (s[26+i-1]=='?'){
                count++;
            }
            else{
                v[(int)s[26+i-1]-(int)'A']++;
            }

            a = check(v,count);
            int k = 0;
            if (a.size()!=0){
                done = true;
                //int l = i;
                j = i;
                for(int cc = 0;cc<26;cc++){
                    if (s[j]=='?'){
                        s[j] = (char)(a[k] + (int)'A');
                        k++;
                    }
                    j++;
                }
                break;
            }
        }
    }

    for(int i = 0;i<s.length();i++){
        if (s[i]=='?'){
            s[i] = 'A';
        }
    }

    if (done)
        cout << s;
    else
        cout << -1;

return 0;
}


