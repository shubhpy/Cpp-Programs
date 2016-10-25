#include <iostream>
#include <vector>

using namespace std;
#define LL long long int

LL loop(vector<int> &vect,vector<int> &num){
    //loop
    LL count=0;
    for(LL i=0;i<vect.size();i++){
        if (vect[num[i]] == num[i]){
            cout << i <<" "<< vect[num[i]] << " " << num[vect[i]]<< "\n";
            count++;
        }
    }

    return count/2;

    }

int valid(vector<int> &vect,vector<int> &num){
    //two roots
    int count=-1;
    for(LL i=0;i<vect.size();i++){
        if (vect[i]==num[i]){
            count++;

        }
    }

    return count;


    }

int main() {
    LL n;
    cin >> n;
    vector<int> vect(n);
    vector<int> num(n);

    for(LL i=0;i<n;i++){
        cin >>  vect[i];
        num[i] = i+1;
    }

    int x;
    int ans = 0;
    x = valid(vect,num);
    if (x==-1){
        ans+=1;
    }
    else{
        ans+=x;
    }

    //cout <<  x << " "<<loop(vect,num);

    cout << ans + loop(vect,num);


    return 0;
}

