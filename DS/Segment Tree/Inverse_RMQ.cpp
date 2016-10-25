#include <bits/stdc++.h>
using namespace std;
#define LL long long int


void constructTree(vector<int> &arr,vector<int> &segTree,int low,int high,int pos){

    if (low==high){
        segTree[pos] = arr[low];
        return ;
    }
    int mid =(high+low)/2;
    constructTree(arr,segTree,low,mid,2*pos +1);
    constructTree(arr,segTree,mid+1,high,2*pos +2);

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
    freopen("inverseRMQ.txt","r",stdin);
    int n;
    cin >> n;
    int segTreeSize = 2*n- 1;

    //vector<int> v(segTreeSize);
    vector<int> arr(n);

    int c;
    unordered_map <int,int> mp;
    int count = 0;

    for(int i = 0;i<segTreeSize;i++){
        cin >> c;
        if (mp[c]==0){
            mp[c]++;
            arr[count] = c;
            count++;
        }
        else{
            mp[c]++;
        }
    }

    //cout << count << " " << n <<"\n"

    sort(arr.begin(),arr.end());

    c = 0;
    if (count==n){
        vector<int> segTree(segTreeSize);
        constructTree(arr,segTree,0,n-1,0);
        for(int i = 0;i<segTreeSize;i++){
            if (mp[segTree[i]]>0){
                mp[segTree[i]]--;
                if (mp[segTree[i]]==0){
                    c++;
                }
            }
            else if (mp[segTree[i]]<=0){
                cout << "NO";
                return 0;
            }
        }
        if (c==n){
            cout << "YES\n";
            for(int i:segTree){
                cout << i << " ";
            }
        }
        else{
            cout << "NO";
        }
    }
    else{
        cout << "NO";
    }
    return 0;
}
