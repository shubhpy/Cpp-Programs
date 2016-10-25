//#include <bits/stdc++.h>

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<string>
#include<iterator>
#include<string>
#include<sstream>
#include<cassert>
#include<ctime>
#include<cmath>
#include<numeric>

#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define oo 2000000000
#define MOD 1000000007
#define LL long long int
#define PII pair<int,int>
#define DEBUG 0

#define getrandom(min, max) ((rand()%(int)(((max) + 1)-(min)))+ (min))
#define PrintDigit(c, d) for(i=0; i < c ; i++)putchar(unit[d]);
#define forn(a,n) for(i=a; i < n ; i++);
using namespace std;

int main(){
    freopen("in1.txt","r",stdin);
	freopen("out4.txt","w",stdout);
    LL T;
    cin >> T;
    //vector<int> vect;
    //vector<vector<LL> > vectQ(Q, vector<LL>(2,0));

    for(int t=0;t<T;t++){
        LL N;
        cin >> N;
        string s;
        vector<string> vectN;
        getline(cin,s);
        for(int i=0;i<N;i++){
            getline(cin,s);
            vectN.push_back(s);
        }

        //cout << vectN[0] << " " <<  sizeof(vectN[1]) << "\n";
        vector<LL> vec;
        for(int i=0;i<N;i++){
            vector<int> let(100);
            for(int l=0;l<100;l++){
                    let[l] = 0;
                }
            for(int j=0;j<vectN[i].length();j++){
                if (vectN[i][j]!=' '){
                let[(int)vectN[i][j] - (int)'A'] +=1;
                }
            }
            LL count=0;

            for(int k=0;k<100;k++){
                if (let[k]!=0){
                    count++;
                }
        }
        vec.push_back(count);
        }

        LL maxe = *max_element(vec.begin(),vec.end());
        LL ocur = count(vec.begin(),vec.end(),maxe);
        //cout << maxe << " "<< ocur << "\n";

        cout << "Case #"<< t+1 << ": ";

        if (ocur==1){
            cout << vectN[find(vec.begin(),vec.end(),maxe) - vec.begin()] << "\n";
        }
        else{
            char str[ocur][20],temp[20];
            for(int i=0;i<ocur;i++){
                for(int j=0;j<vec.size();j++){
                    if (vec[j]==maxe){
                        for(int k=0;k<vectN[j].length();k++){
                            str[i][k]  = vectN[j][k];
                            }
                        i++;
                    }
                }
            }
        for(int i=0;i<ocur-1;++i)
       for(int j=i+1;j<ocur;++j){
          if(strcmp(str[i],str[j])>0)
          {
            strcpy(temp,str[i]);
            strcpy(str[i],str[j]);
            strcpy(str[j],temp);
          }
    }
            cout <<  str[0] << "\n";
        }

    //cout << "Case #" << t+1 <<":" << "\n";
    //for(i=0; i < n ; i++){

    //}
    }
        return 0;
}
