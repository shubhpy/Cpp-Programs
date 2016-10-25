#include <iostream>

using std::cin;
using std::cout;

int EucledianGCD (int a,int b) {
    int temp;
    cout<<cont+1<< "\n";
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
        cout << EucledianGCD(a,b);
        }
    else
        cout << EucledianGCD(b,a);
    return 0;
}
