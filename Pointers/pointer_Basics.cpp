#include<iostream>

using namespace std;

void printxC(int* x){
    cout << *x << "\n";
    *x = *x + 10;
    }

void printxCpp(int& x){
    cout << x << "\n";
    x = x + 10;
    }

int main(){

    int y=10;

    printxC(&y);

    cout << y << "\n";

    printxCpp(y);

    cout << y << "\n";

    return 0;
}

