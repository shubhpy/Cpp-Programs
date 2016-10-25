#include<iostream>
#include<vector>
using namespace std;
#define LL long long int


int main(){
    LL Y;
    cin >> Y;

    if (Y%400==0 || (Y%4==0 && Y%100!=0)){
        cout << Y + 28;
    }
    else if (Y%400==1 || (Y%4==1 && Y%100!=0)){
        cout << Y + 6;
    }
    else if (Y%400==2 || (Y%4==2 && Y%100!=0)){
        cout << Y + 11;
    }
    else if (Y%400==3 || (Y%4==3 && Y%100!=0)){
        cout << Y + 5;
    }

return 0;
}
