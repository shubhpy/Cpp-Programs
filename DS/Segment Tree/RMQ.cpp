#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
#define LL long long int


void constructTree(vector<int> &v,vector<int> &segTree,int low,int high,int pos){

    if (low==high){
        segTree[pos] = v[low];
        return ;
    }
    int mid =(high+low)/2;
    constructTree(v,segTree,low,mid,2*pos +1);
    constructTree(v,segTree,mid+1,high,2*pos +2);

    segTree[pos] = min(segTree[2*pos +1],segTree[2*pos +2]);

}

int RMQ(vector<int> &segTree,int qlow, int qhigh,int low,int high, int pos){

    if (qlow<=low && qhigh>=high){
        return segTree[pos];
    }
    if (qlow>high || qhigh<low)
        return INT_MAX;

    int mid = (low+high)/2;

    return min(RMQ(segTree,qlow,qhigh,low,mid,2*pos+1),RMQ(segTree,qlow,qhigh,mid+1,high,2*pos+2));
}


int main() {
    freopen("rmq.txt","r",stdin);
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0;i<n;i++){
        cin >> v[i];
    }

    int segTreeSize = 2*pow(2,ceil(log10(n)/log10(2))) - 1 ;
    vector<int> segTree(segTreeSize,INT_MAX);

    constructTree(v,segTree,0,n-1,0);

    for(int i:segTree){
        cout << i << " ";
    }
    cout << "\n";

    //cout << RMQ(segTree,1,3,0,n-1,0);

    return 0;
}
