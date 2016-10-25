#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define LL long long int

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //LL n,x;
    //cin >> n;

    string s,si;
    cin >> s;
    cin >> si;

    cout << s <<endl;
    int x = stoi(si);

    cout << x;
    /*

    vector<LL> v(n,0);
    vector<LL> ans(n,0);
    vector<LL> out(n,0);
    vector<LL> in(n,0);
    LL j = 0;
    string s;
    LL count = 1;
    LL palimin = 0;
    LL palimout = 0;
    //cout <<  0 << "\n";
    cin >> s;
    s[0]='0';
    s[1]='0';
    x = stoi (s,&sz);
    v[0] = x;
    ans[0]=0;
    out[0]=0;
    in[0]=0;
    for(int i=1;i<n;i++){
        cin >> s;
        if (s[0]=='+'){
            count++;
            s[0]='0';
            s[1]='0';
            x = stoi (s,&sz);
            v[i] = x;
            cout << x << "\n";
            if (x==v[0]){
                palimout++;
            }
            else if (x!=v[0]){
                palimout--;
                if (palimout<0){
                    palimout = 0;
                }
            }
            else if (x==v[count-2]){
                palimin++;
            }

            if (count/2 == palimin + palimout){
                ans[i]=count-1;
                out[i]=palimout;
                in[i]=palimin;
            }
            else{
                ans[i]=palimout;
                out[i]=palimout;
                in[i]=palimin;
            }
        }
        else if(s[0]=='-'){
            v[count] = 0;
            count--;
            ans[i] = ans[i-2];
            palimout = out[i-2];
            out[i] = palimout;
            palimin = in[i-2];
            in[i] = palimin;

        }
    }

    for(int i=0;i<n;i++){
        cout << ans[i] << "\n";
    }
*/

    return 0;
}
