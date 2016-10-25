#include<iostream>

using namespace std;

int main(){

    int i = 5;
    char b = 'b';

    int a = 10;
    void *p = &a;
    cout << *(int *)p << "\n";

    void *ptr;

        cout<<&b<< "    b\n";
            cout<<&i<< " i\n";

    ptr = &b;

        cout<< ptr<< "  1\n";
    ptr = &i;
        cout<< ptr<< "    2\n";

        cout<< *(int *)ptr<< " \n";
    }

