#include <iostream>

using std::cin;
using std::cout;

long long EucledianGCD (int a,int b) {
    int temp;
    if (b!=0){
        temp=b;
        b=a%b;
        a=temp;
        EucledianGCD(a,b);
        }
    else
        return a;

}

int main() {
    int a,b;
    cin >> a >> b ;
    if (a>b){
        cout << (a/EucledianGCD(a,b))*b;
        }
    else{
        cout << (b/EucledianGCD(b,a))*a;
        }
    return 0;
}
