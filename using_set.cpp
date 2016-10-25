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

    cout << *it;

    cout << *(myset.end());

    cout << *myset.begin();

}
