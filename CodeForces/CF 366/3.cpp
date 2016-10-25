#include<iostream>
#include<vector>
#include<limits.h>
#include<stack>
using namespace std;

int main(){

    long long int n,q,t,x;
    cin >> n >>  q;

    vector<long long int> v(n+1,0);
    vector<long long int> st;
    vector<long long int> stc;

    long long int count = 0;
    long long int temp ;

    for(int i=0;i<q;i++){
        cin >>  t >> x;
        if (t==1){
            st.push_back(x);
            stc.push_back(1);
            v[x]+=1;
            count++;
        }
        else if(t==2){
            count-=v[x];
            v[x] = 0;
        }
        else if (t==3){
            for(int j=0;j<x;j++){
                if (v[st[j]]!=0 && stc[j]==1){
                    v[st[j]]-=1;
                    stc[j]=0;
                    count--;
                }
                else if (v[st[j]]==0){
                    stc[j]=0;
                }
            }

        }

        cout << count << "\n";
    }

    return 0;
        }
