#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define LL long long int

int main(){
    int T;

    LL R,N,c,a,b;
    cin >> T;

    for(int t=0;t<T;t++){
        cin >> R >> N;

        vector<LL> r(R);

        for(int i=0;i<R;i++){
            cin >> c;
            r[i] = c*c;
        }

        sort(r.begin(),r.end());

        LL count = 0;
        for(int i=0;i<N;i++){
                cin >> a >> b;
                auto x = lower_bound(r.begin(),r.end(),a*a+ b*b) - r.begin();

                count+=R-x;
        }

        cout << count << "\n";

    }
    return 0;
    }



