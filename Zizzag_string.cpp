#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// PAHNAPLSIIGYIR
string convert(string A, int B) {

    if (B==1){
        return A;
    }

    int c = 2*(B-1);

    string s = "";

    int a = c;
    int b = 0;
    int t = 0;
    for(int i = 0;i<B;i++){

        if (a==c || b==c){
            for(int l = i;l<A.length();l+=c){
                    s+=A[l];
                }
        }
        else{
            int count = 1;
            for(int l = i;l<A.length();){
                    if (count%2==1){
                        s+=A[l];
                        l+=a;
                        count++;
                    }
                    else{
                        s+=A[l];
                        l+=b;
                        count++;
                    }
                }
        }
        a = a-2;
        b = b+2;
    }
    return s;

    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}


int main() {
    cout << convert("ABCD",2);
}
