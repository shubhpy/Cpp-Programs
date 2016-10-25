#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

void check(int A, vector<int> &B,int &mn,vector<int> &ans){

    vector<int> v;
    v.push_back(0);
    v.push_back(A);

    int sum = 0;
    for(int i = 0;i<B.size();i++){
        int u = upper_bound(v.begin(),v.end(),B[i]) - v.begin();
        int l = lower_bound(v.begin(),v.end(),B[i]) - v.begin();
        sum = sum + v[u] - v[l-1];
        v.insert(lower_bound(v.begin(),v.end(),B[i]),B[i]);
    }

    if (mn>sum){
        ans = B;
        mn = sum;
    }
    else if (mn==sum){
        for(int i = 0;i<B.size();i++){
            if (ans[i]!=B[i]){
                if (ans[i]>B[i]){
                    ans = B;
                    break;
                }
                else{
                    break;
                }
            }
        }
    }
}


vector<int> rodCut(int A, vector<int> &B) {

    int n = B.size();
    int mn = INT_MAX;
    vector<int> ans;
    ans = B;
    sort(B.begin(),B.end());

    do {
        check(A,B,mn,ans);
    } while ( next_permutation(B.begin(),B.end()));


    // cout << mn << "\n";

    return ans;

}


int main(){
    int A = 100;
        vector<int> B = {2, 3, 6, 7, 14, 22, 25, 30, 34, 45, 51, 52, 54, 56, 57, 58, 59, 61, 63, 66, 76, 78};

        vector<int> res;

        res  = rodCut(A,B);

        for(int i:res){
            cout << i << " ";
        }

return 0;
}


void solve(vector<int> &A,int l,int r,vector<int> &ans,map< pair<int,int> , long long > &mp,map< pair<int,int> , int > &index){

    if(r-l<=1) {
        mp[{l,r}]=0;
    }

    if(mp.find({l,r})!=mp.end()) return;

    long long cost=1e15;
    int mn=l+1;

    for(int i=l+1;i<r;i++){
        if(mp.find({l,i})==mp.end()) solve(A,l,i,ans,mp,index);
        if(mp.find({i,r})==mp.end()) solve(A,i,r,ans,mp,index);

        if(cost > mp[{l,i}] + mp[{i,r}] + A[r]-A[l]){
            cost=mp[{l,i}] + mp[{i,r}] + A[r]-A[l];
            mn=i;
        }
    }
    mp[make_pair(l,r)]=cost;
    index[{l,r}]=mn;

    //cout<<l<<" "<<r<<" "<<mn<<" " <<cost+r-l <<endl;
}

void fillA(int l,int r,vector<int> &A,vector<int> &ans,map< pair<int,int> , long long > &mp,map< pair<int,int> , int > &index){
    if(r-l<=1) return;

    int i=index[{l,r}];
    ans.push_back(A[i]);

    //cout<<l<<" "<<r<<" "<<i<<endl;

    fillA(l,i,A,ans,mp,index);
    fillA(i,r,A,ans,mp,index);
}

vector<int> Solution::rodCut(int N, vector<int> &A) {
    vector<int> ans,B;

    B.push_back(0);
    for(auto x:A) B.push_back(x);
    B.push_back(N);

    int n=B.size();

    map< pair<int,int> , long long > mp;
    map< pair<int,int> , int > index;

    solve(B,0,n-1,ans,mp,index);

    fillA(0,n-1,B,ans,mp,index);

    return ans;
}
