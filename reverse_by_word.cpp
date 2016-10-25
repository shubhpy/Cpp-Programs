#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void reverseWords(string A) {

    bool space = false;
    bool chr = false;
    string res = "";

    int l = A.length()-1;
    while(l>=0){
        if (A[l]==' '){
            if (!space){
                if (chr)
                    res+=" ";
                space = true;
                chr = false;
            }
        }
        else{
            space = false;
            chr = true;
            res+=A[l];
        }
        l--;

    }

    int last = 0;
    for(int i =0 ;i<res.length();i++){
        if (res[i]==' '){
            reverse(res.begin()+last,res.begin()+i);
            last = i+1;
        }
    }

    reverse(res.begin()+last,res.begin()+res.length());

    for(int i = 0;i<res.length();i++){
        cout <<  res[i];
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}


int main(){

    reverseWords("l");

}
