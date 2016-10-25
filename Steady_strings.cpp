#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long int


bool check(LL i,LL k,vector<pair<char,LL> >& vect1,LL ca,LL cg,LL ct,LL cc){
       LL gca = ca;
    LL gcg = cg;
 LL gct = ct;
    LL gcc = cc;

    for(LL j = i ;j<k;j++)
        {
        if (gca!=0 && vect1[j].first == 'A'){
            ca--;
        }
        else if (gcg!=0 && vect1[j].first == 'G'){
            cg--;
        }
        else if (gct!=0 && vect1[j].first == 'T'){
            ct--;
        }
        else if (gcc!=0 && vect1[j].first == 'C'){
            cc--;
        }
    }

    return (ca==0 && cg==0 && ct==0 && cc ==0);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    freopen("hr2.txt","r",stdin);
    LL n ;
    cin >>  n;
    string s;
    cin >> s;

    LL ca=0;
    LL ct=0;
    LL cg=0;
    LL cc = 0;

    for(int i=0;i<n;i++){
        if (s[i]=='A'){
            ca++;
        }
        else if (s[i]=='T'){
            ct++;
        }
        else if (s[i]=='G'){
            cg++;
        }
        else{
            cc++;
        }
    }

    LL count=0;

    bool bca = false;
    bool bcg = false;
    bool bct = false;
    bool bcc = false;

    if (ca>n/4){
       ca = ca - (n/4);
       bca = true;
    }
    else{
        ca=0;
    }

    if (cg>n/4){
       cg = cg - (n/4);
       bcg = true;
    }
    else{
        cg=0;
    }

    if (ct>n/4){
       ct = ct - (n/4);
       bct = true;
    }
    else{
        ct=0;
    }

    if (cc>n/4){
       cc = cc - (n/4);
       bcc = true;
    }
    else{
        cc=0;
    }

    count=ca+ct+cg+cc;

    cout << count << " " <<  ca  << " " <<ct << " " << cg << " " << cc<< "\n";

    if (count!=0){
    vector<pair<char,LL> > vect1;

    pair<char,LL> mp;

    for(LL i=0;i<n;i++){
        if (bca && s[i]=='A'){
            mp = make_pair('A',i);
            vect1.push_back(mp);
        }
        else if (bcg && s[i]=='G'){
            mp = make_pair('G',i);
            vect1.push_back(mp);
        }
        else if (bct && s[i]=='T'){
            mp = make_pair('T',i);
            vect1.push_back(mp);
        }
        else if (bcc && s[i]=='C'){
            mp = make_pair('C',i);
            vect1.push_back(mp);
        }
    }

    cout <<  vect1.size() << "\n";

    vector<LL> ansvect;
    for(LL i=0;i<=vect1.size()-count;i++){
        if (check(i,i+count,vect1,ca,cg,ct,cc)){
            cout << i << " " <<vect1[i+count-1].second - vect1[i].second +1 << "\n";
            ansvect.push_back(vect1[i+count-1].second - vect1[i].second +1);
        }
    }

    auto  p = min_element(ansvect.begin(),ansvect.end());
    cout << *p;
    }
    else{
        cout < 0;
    }
    return 0;
}
