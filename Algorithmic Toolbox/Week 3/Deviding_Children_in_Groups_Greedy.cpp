#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int PointsCoverSorted(vector<float>& x,int n,int L){

    int Currently_at = 0;
    int i;
    while(Currently_at<n-1){
        for(i=Currently_at;i<n;i++){
            if(x[i]-x[Currently_at]<=L){
                cout << x[i] << " " ;
                }
            else{
                break;
                }
            }
            Currently_at=i;
        cout<<"\n";
    }
    return 0;
}


int main() {
    int n;
    int L;
    cin >> n >> L;
    vector<float> x(n+1);
    for(int i=0;i<n;i++){
        cin >> x[i];
    }

    PointsCoverSorted(x,n,L);

    return 0;
}

