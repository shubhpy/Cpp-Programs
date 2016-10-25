#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long int

struct il
{
    LL s, e;
};


bool mycomp(il a, il b)
{
    return a.s > b.s;
}

int merge(vector<vector<il> > &v,LL r){
    if (v[r].size()==0){
        return ;
    }

    if (v[r].size()==1){
        vindex[r] = 1;
        return ;
    }
    int n = v[r].size();
    sort(v[r].begin(), v[r].end(), mycomp);

    LL index = 0;
    for (int i=0; i<n; i++)
    {
        if (index != 0 && v[r][index-1].s <= v[r][i].e)
        {
            while (index != 0 && v[r][index-1].s <= v[r][i].e)
            {
                v[r][index-1].e = max(v[r][index-1].e, v[r][i].e);
                v[r][index-1].s = min(v[r][index-1].s, v[r][i].s);
                index--;
            }
        }
        else
            v[r][index] = v[r][i];

        index++;
    }
    return index;

}

int main() {
    //freopen("gridland.txt","r",stdin);
    LL n,m;
    int k;
    cin >> n >> m >> k;
    vector<LL> row;
    vector<vector<il> > v(1001,vector<il>());
    LL r,c1,c2;
    for(int i  = 0;i<k;i++){
        cin >> r >> c1 >> c2;
        bool flag=true;
        for(int i=0;i<row.size();i++){
            if(r==row[i]){
                v[i].push_back((il){c1,c2});
                flag=false;
            }
        }
        if(flag){
            row.push_back(r);
            v[row.size()-1].push_back((il){c1,c2});
        }
    }

    LL ans = n*m;
    for(int i  = 0;i<row.size();i++){
        int index = merge(v,i);
        for(int j = 0;j<index;j++){
            ans = ans - (v[i][j].e - v[i][j].s) - 1;
        }
    }

    cout << ans;
    return 0;
}
