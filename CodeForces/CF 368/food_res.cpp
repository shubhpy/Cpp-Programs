#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define LL long long int

bool mycomp(const pair<LL,LL> &a, const pair<LL,LL > &b){
	return a.second<b.second;
}

int main() {
    LL T;
    cin >> T;
    vector<pair<LL,LL> > v(T);
    LL i;
    for(int t=0;t<T;t++){
        cin >> v[t].first >> v[t].second;
    }
    sort(v.begin(),v.end(),mycomp);

    LL prev = 0;
    LL sumi = 0;
    LL modi = 0;

    for(int t=0;t<T;t++){
        prev = prev+v[t].second;
        sumi=sumi + (prev - v[t].first)/T;
        modi += (prev -v[t].first)%T;
        if (modi>=T){
        	modi = modi%T;
        	sumi+=modi/T;
        }
    }
    cout << sumi;


}
