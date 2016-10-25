#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int>  a;
    a = {2, 2, 5, 6, 8, 8, 12};

    int up = upper_bound(a.begin(),a.end(),10) - a.begin() ;
    int down = lower_bound(a.begin(),a.end(),10) - a.begin() ;

    cout << up << " " << down << "\n";

    /*a.insert(lower_bound(a.begin(), a.end(), 1), 1);
    //a.insert(upper_bound(a.begin(), a.end(), 2), 8);

    for(int i=0;i<a.size();i++)
        cout << a[i] << " " ;
    */

    return 0;
}
