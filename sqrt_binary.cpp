#include<iostream>
#include<vector>
#include<string>
using namespace std;

int binary(int low,int high,int A){
    if (high==low){
        return low;
    }

    int mid  = low + (high-low)/2;
    // cout <<  low << " " << high << " " << mid << "\n";

    long long int p = mid*mid;
    if (p==A){
        return mid;
    }
    else if (p<A){
        return binary(mid+1,high,A);
    }
    else if (p>A){
        return binary(low,mid-1,A);
    }

}

int qrt(int A) {

    if (A==0){
        return 0;
    }
    if (A==1 || A==2 ||A==3){
        return 1;
    }

    return binary(1,A,A);
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}


int main(){
    cout << qrt(361746049);
    //361746042
}

