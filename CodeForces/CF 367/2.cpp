#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<cmath>

using namespace std;
#define LL long long int
#define fi first
#define se second


LL binary(LL x,vector<LL> &v,LL low,LL high){

        if (high<low){
            return low;
        }
        LL mid = std::floor(low  + (high-low)/2);

        if (v[mid]==x){
                LL ans = mid+1;
                //return mid+1;
                int cr = mid+1;
                while(v[cr]==x){
                    cr++;
                    ans++;
                }

                return ans;

            }
        else if( x < v[mid]){
            return binary(x,v,low,mid-1);
            }
        else{
            return binary(x,v,mid+1,high);
            }
        }


int main(){
        LL n,q;

        cin >> n;
        vector<LL> v(n);
        for(LL i=0;i<n;i++){
            cin >> v[i];
        }

        sort(v.begin(),v.end());

        cin >> q;
        LL x;
        for(LL i=0;i<q;i++){
            cin >> x;
            cout << binary(x,v,0,n-1) << "\n";
        }

        return 0;
    }

