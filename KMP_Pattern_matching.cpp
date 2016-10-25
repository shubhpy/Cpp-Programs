#include<iostream>
#include<vector>
#include<string>

using namespace std;

void compute(vector<int> &v,string P){
    int m = P.length();
    int k = 0;
    v[0] = 0;

    for(int i=1;i<m;i++){
        while(k>0 && P[k]!=P[i]){
            k = v[k-1];
        }
        if (P[k]==P[i]){
            k++;
        }
        v[i]=k;
    }
}

void kmpMatcher(string T,string P){
    int n = T.length();
    int m = P.length();

    int q = 0;
    vector<int> v(m);;
    compute(v,P);

   // for(int i=0;i<m;++i){
   //     cout << v[i] << " ";
   //     }
   // cout << "\n";


    for(int i=0;i<n;++i){
        while(q>0 && P[q]!=T[i]){
            q = v[q-1];
        }
        if (P[q]==T[i]){
            //cout << q << " " << i << " ++ ";
            q++;
        }
        if (q==m){
            cout << "Pattern Found at " << i-m +1 << "\n";
            q= v[q-1];
        }

        //cout << q << "\n";
    }
}


int main(){
    //kmpMatcher( "AABAACAADAABAAABAA","AABA");
    kmpMatcher( "AAAACAAAAAAAAAAAAC","AAAAC");
    return 0;

}
