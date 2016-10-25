#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define LL long long int

int main(){
    LL T;
    cin >> T;
    for(int t=0;t<T;t++){
        LL N,A;
        int e;
        LL prev = 0;
        cin >> N;
        vector<int> V;
        LL P = 0;

        vector<int> B(1001,0);

        vector<pair<LL,LL> > addr(N);
        for(int i=0;i<N;i++){
            cin >> A;
            if (i==0){
                addr[i].first = 0;
                addr[i].second = A;
                prev = prev + A;
            }
            else{
                addr[i].first = prev;
                addr[i].second = A;
                prev = prev + A;
            }
            for(int i=0;i<A;i++){
                cin >> e;
                V.push_back(e);
            }
            P+=A;
        }

        vector<int> seq(P);
        for(int i=0;i<P;i++){
            cin >> seq[i];
        }

        reverse(seq.begin(),seq.end());

        int i;
        bool no = false;
        for(i=0;i<P;i++){
            bool match = false;
            for(int j=0;j<N;j++){
                if (addr[j].second>0){
                    if (V[addr[j].first]==seq[i]){
                        if (match!=true){
                            addr[j].first++;
                            addr[j].second--;
                            match = true;
                        }
                        else{
                            B[seq[i]]++;
                            addr[j].first++;
                            addr[j].second--;
                        }
                    }
                }
            }
            if (!match){
                for(int k=1;k<1001;k++){
                    if (B[seq[i]]!=0){
                        B[seq[i]]--;
                        match = true;
                        break;
                    }
                }
                if (!match){
                    cout << "No\n";
                    no = true;
                    i = P;
                    break;
                }
            }
        }

        if (!no){
            cout << "Yes\n";
        }


    }
    return 0;
    }


