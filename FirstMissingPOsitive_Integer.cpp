#include<iostream>
#include<vector>
#include<string>
using namespace std;

int firstMissingPositive(vector<int> &A) {

    if (A.size()==0){
        return 1;
    }

    if (A.size()==1){
        if (A[0]<=0){
            return 1;
        }
        else if (A[0]==1){
            return 2;
        }
        else if (A[0]>1) {
            return 1;
        }
    }

    int N = A.size();
    int p,t;

    //cout <<  N << "\n";

    for(int i=0;i<A.size();i++){
            //cout <<  A[i] << "\n";
        if (A[i]>0 && A[i] <= N){
            t = A[A[i]-1];
            A[A[i]-1]=-1;
            while(t>0 && t<=N){
                //cout << t << " ";
                p = t-1;
                t = A[t-1];
                A[p] = -1;
            }
        }
    }

    //cout << "here\n";
    int count = 0;
    int ans;
    for(int i=0;i<A.size();i++){

        //cout << A[i] << " ";
        if (A[i]>0){
            return i+1;
        }
        else if (A[i]<=0){
            if (A[i]==-1)
                ans = i+2;
            count++;
        }
    }

    if (count==N){
        return ans;
    }

    return 1;
}


int main(){
    freopen("positiveint.txt","r",stdin);
	//freopen("out6.txt","w",stdout);
    int n;
    cin >>  n;
    vector<int> A(n);

    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    cout << firstMissingPositive(A);

}
