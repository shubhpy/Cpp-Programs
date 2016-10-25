/*
Exam No 3 Character Recognition
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("char.txt","r",stdin);
    int n,m,k;
    string s;
    cin>>n>>m>>k;
    int mat[k+1][n+1][m+1];
    /*This above loop stores the differnt no in characters in a matrix named mat */
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cin >> s;
            for(int l=1;l<=m;l++){
                mat[i][j][l] = (int)(s[l-1] - '0');
            }
        }
    }

    vector<set<pair<int,int> > > vec;
    /*This vector of sets of pairs stores all the different positions
    of two character matrices where these differ from each other.
    each set contanis those pairs from two distict character matrices.
    So vector's size will be kC2.
    */
    for(int i=1;i<=k;i++){
        for(int j=i+1;j<=k;j++){
            set<pair<int,int> > temp;
            for(int x=1;x<=n;x++){
                for(int y=1;y<=m;y++){
                    if(mat[i][x][y] != mat[j][x][y]){
                        temp.insert(make_pair(x,y));
                    }
                }
            }
            vec.push_back(temp);
        }
    }
    map<pair<int,int>,int> mp;
    /*This map of pairs as key and int as their value will contain all the pairs of vec vector
    which sets are not taken.*/
    vector<int> taken(vec.size(),0);
    bool done = 0;
    int ans = 0;
    for(int i=0;i<vec.size();i++){
        for(auto it = vec[i].begin();it!=vec[i].end();it++){
            mp[*it]++;
        }
    }
    while(!done)
    {
        int maxi = 0;
        pair<int,int> temp;
        for(auto it = mp.begin() ; it!=mp.end() ; it++){
            if(it->second > maxi){
                temp = it->first;
                maxi = it->second;
            }
        }
        for(int i=0;i<vec.size();i++){
            if(!taken[i] && vec[i].find(temp)!=vec[i].end()){
                taken[i] = 1;
                for(auto it = vec[i].begin();it!=vec[i].end();it++){
                    mp[*it]--;
                }
            }
        }
        ans++;
        int i;
        for(i=0;i<taken.size();i++){
            if(!taken[i])
                break;
        }
        if(i==vec.size())
            done = 1;
    }
    cout<<ans;
    return 0;
}

//34dccca8-d9bd-4992-83ae-9630819df155
