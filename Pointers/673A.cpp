#include<iostream>
#include<string.h>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>> n;
    vector<int> a(92);
    a[0]=0;
    for(int i=1;i<n+1;i++){
    cin>>a[i];
    }
    a[n+1]=90;

    int diff=0;
    int count=0;
    for(int i=0;i<n+1;i++){
        if (a[i+1]-a[i] <= 15){
            diff+=a[i+1]-a[i];
        }
        else{
            diff+=15;
            break;
        }
    }

    cout<< diff;

}

