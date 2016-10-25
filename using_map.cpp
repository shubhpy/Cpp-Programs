#include<iostream>
#include<vector>
#include <unordered_set>
#include<algorithm>
#include<set>

using namespace std;

int main(){
    vector<int>  a;
    a = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3};

    set<int> myset;
    set<int>::iterator it;

    for (int i=1; i<=6; i++) myset.insert(i*10);

    it=myset.find(60);

    for (it=myset.begin(); it!=myset.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';

    myset.


    //cout << *it;

    cout << *(myset.end());

    /*

    set<int> s;

    s.insert(12);

    s.insert(1);

    cout << *s.find(2);

    //for(int i=0;i<a.size();i++){
    //    if (s.find(s.begin()+i+1,s.end(),a[i])){
//

  //  }

*/
  cout << "\n";
    sort(a.begin(),a.end());

    cout << upper_bound(a.begin(),a.end(),5) - a.begin() << "\n";
    cout << lower_bound(a.begin(),a.end(),5) - a.begin() << "\n";

    a.insert(lower_bound(a.begin(), a.end(), 5), 6);
    a.insert(upper_bound(a.begin(), a.end(), 8), 8);

    for(int i=0;i<a.size();i++)
        cout << a[i] << " " ;
}

//{12, 1, 12, 3, 12, 1, 1, 2, 3, 3}
