#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

#define LL long long int
#define F first
#define S second

int day(string s){

    if (s=="sunday")
        return 1;
    if (s=="monday")
        return 2;
    if (s=="tuesday")
        return 3;
    if (s=="wednesday")
        return 4;
    if (s=="thursday")
        return 5;
    if (s=="friday")
        return 6;
    if (s=="saturday")
        return 7;
}
int main(){

    //freopen("days.txt","r",stdin);
    string a,b;
    cin >> a >> b;
    int i = day(a);
    int j = day(b);
/*
    vector<int> m (12);
    m = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
*/

    if (i==j){
            cout << "YES";
            return 0;
        }
    if ((i+2)%7==j){
        cout << "YES";
            return 0;
        }
    if ((i+3)%7==j){
        cout << "YES";
            return 0;
        }

    cout << "NO";
    return 0;

}

