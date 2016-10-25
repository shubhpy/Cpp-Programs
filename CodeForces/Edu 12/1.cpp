
#include<iostream>

using namespace std;

int main(){
    int a,ta,b,tb;
    cin >> a >>  ta;
    cin >> b >> tb;
    string t;
    cin >> t;
    int hh = ((int)t[0] - (int)'0')*10 + ((int)t[1] - (int)'0');
    int mm = ((int)t[3] - (int)'0')*10 + ((int)t[4] - (int)'0');

    int min_min = 5*60;
    int max_min = 23*60 + 59 ;
    int min = hh*60 + mm;

    int ans = 0;
    int temp;
    if (min - tb > min_min){
        temp = min - tb;
        while(temp<min){
            ans++;
            temp = temp  + b;
        }
    }
    else{
        temp = min_min;
        while(temp<min){
            ans++;
            temp = temp  + b;
        }

    }

    //cout << ans << " "  << temp <<   "\n";

    if (temp==min){
        ans++;
    }
    temp = temp - b;



    int temp2 = temp + b;
    if (temp + ta > max_min){
        while(temp2<max_min){
            ans++;
            temp2 = temp2  + b;
        }
    }
    else{
        while(temp2<temp + ta){
            ans++;
            temp2 = temp2  + b;
        }

    }

    cout << ans;

    return 0;
}

