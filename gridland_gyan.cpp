#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int LLI;


struct track{
    int st,end;
};

vector <vector <track *> > vtk(1001);
vector <int> row;

void add(int r,int c1,int c2){
    track *tk=new track;
    tk->st=c1;
    tk->end=c2;
    vtk[r].push_back(tk);
}

void insert(int r,int c1,int c2){
    bool flag=true;
    for(int i=0;i<row.size();i++){
        if(r==row[i]){
            add(i,c1,c2);
            flag=false;
        }
    }
    if(flag){
        row.push_back(r);
        add(row.size()-1,c1,c2);
    }
}

struct comp{
    bool operator()(const track *t1,const track *t2){
        return t1->st<t2->st;
    }
};

int main() {
    int n,m,k,r,c1,c2;
    cin>>n>>m>>k;
    LLI lpost=(LLI)n*(LLI)m;
    for(int i=0;i<k;i++){
        cin>>r>>c1>>c2;
        insert(r,c1,c2);
    }
    for(int i=0;i<1001;i++){
        sort(vtk[i].begin(),vtk[i].end(),comp());
        int sz=vtk[i].size(),c1,c2;
        if(!vtk[i].empty()){
            c1=vtk[i][0]->st;
            c2=vtk[i][0]->end;
        }
        else continue;
        int x=0,j=1;
        while(j<sz){
            if(vtk[i][j]->st<c2){
                c2=max(vtk[i][j]->end,c2);
            }
            else{
                lpost-=(c2-c1+1);
                c1=vtk[i][j]->st;
                c2=vtk[i][j]->end;
            }
            j++;
        }
        lpost-=(c2-c1+1);
    }
    cout<<lpost;
    return 0;
}
