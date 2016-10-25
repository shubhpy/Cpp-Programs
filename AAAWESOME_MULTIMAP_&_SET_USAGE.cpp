#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define oo 2000000000
#define MOD 1000000007
#define LL long long int
#define PII pair<int,int>
#define DEBUG 0

using namespace std;

void fourSum(vector<int> &num, int target) {
        vector<int> res_m(4);
        vector< vector<int> > res;
        multimap<int, pair<int,int> > mp;
        multimap<int, pair<int,int> >::iterator mit,mit2;
        set<vector<int> > mset;

        //Get all pair sums (every two-elements sums)
        for (int i=0;i<num.size()-1;i++){
            for (int j=i+1;j<num.size();j++){
                mp.insert(make_pair((num[i]+num[j]),make_pair(i,j)));
            }
        }

        //Use a multi map to find the results
        for (mit=mp.begin();mit!=mp.end();mit++){
            if (mp.find(target- (*mit).first)!=mp.end()){ // if the target-current value exists in the map

                //handling the same key multi-value case
                pair <multimap<int,pair<int,int> >::iterator, multimap<int,pair<int,int> >::iterator> ret;
                ret = mp.equal_range(target- (*mit).first);

                //for all the values in the same key
                for (mit2=ret.first;mit2!=ret.second;++mit2){

                    //check if duplicates exist in the two pairs
                    if (mit->second.first != mit2->second.first && mit->second.first != mit2->second.second && mit->second.second != mit2->second.first && mit->second.second != mit2->second.second){
                        res_m[0]=(num[mit->second.first]);
                     res_m[1]=(num[mit->second.second]);
                     res_m[2]=(num[mit2->second.first]);
                     res_m[3]=(num[mit2->second.second]);
                     sort(res_m.begin(),res_m.end());
                     mset.insert(res_m); // handles the duplicates
                    }
                }
            }
        }

        //get result
        for (set<vector<int> >::iterator it=mset.begin();it!=mset.end();++it){
            res.push_back(*it);
     }

     for(int i= 0;i<res.size();i++){
        cout << res[i][0] << " " << res[i][1] <<  " " << res[i][2] <<  " " << res[i][3] << "\n";
     }

    }


    int main(){
            vector<int> num = {9, -8, -10, -7, 7, -8, 2, -7, 4, 7, 0, -3, -4, -5, -1, -4, 5, 8, 1, 9, -2, 5, 10, -5, -7, -1, -6, 4, 1, -5, 3, 8, -4, -10, -9, -3, 10, 0, 7, 9, -8, 10, -9, 7, 8, 0, 6, -6, -7, 6, -4, 2, 0, 10, 1, -2, 5, -2};
            int target = 0;
            fourSum(num,target);

            return 0;
    }
