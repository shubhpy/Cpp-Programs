#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
#define LL long long int

int main() {
    int t=1;
    cin >> t;
    string s;
    for(int i  = 0;i<t;i++){
        cin >> s;
        if (s[0]=='*' || s[s.length()-1]=='*'){
            cout << "Syntax Error\n";
        }
        else{
            LL ans = 1;
            LL no = 0;
            int last = 0;
            int count = 0;
            int err = 0;
            stack<LL> st;
            for(int i = 0;i<s.length();i++){
                if (s[i]!='*'){
                    count = 0;
                    no = 10*no + ((int)(s[i]-'0'));
                }
                else{
                    cout << last << " " << no << "\n";
                    if (count==0){
                        if (last==0){
                            st.push(no);
                            no = 0;
                        }
                        else if (last==1){
                            st.push(no);
                            no = 0;
                        }
                        else if (last==2){
                            LL t = st.top();
                            st.pop();
                            st.push(pow(t,no));
                            no=0;
                        }
                    }
                    count++;
                    last = count;
                    if (count==3){
                        err = 1;
                        cout << "Syntax Error\n";
                        break;
                    }
                }

            }
            if (err==0){
                if (last==0){
                    st.push(no);
                    no = 0;
                }
                if (last==1){
                    st.push(no);
                    no = 0;
                }
                else if (last==2){
                    LL t = st.top();
                    st.pop();
                    st.push(pow(t,no));
                    last = 0;
                }

                while(!st.empty()){
                    cout << st.top() << "\n";
                    ans = ans*st.top();
                    st.pop();
                }

                cout << ans << "\n";
            }

        }
    }

    return 0;
}
