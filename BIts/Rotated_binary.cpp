#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int findMinIndex(const vector<int> &A, int low,int high){

    if (high < low)  return 0;

    // If there is only one element left
    if (high == low) return low;

    // Find mid
    int mid = low + (high - low)/2; /*(low + high)/2;*/

    // Check if element (mid+1) is minimum element. Consider
    // the cases like {3, 4, 5, 1, 2}
    if (mid < high && A[mid+1] < A[mid])
       return mid+1;

    // Check if mid itself is minimum element
    if (mid > low && A[mid] < A[mid - 1])
       return mid;

    // Decide whether we need to go to left half or right half
    if (A[high] > A[mid])
       return findMinIndex(A, low, mid-1);
    return findMinIndex(A, mid+1, high);
}

int binary(const vector<int> &A, int low,int high,int B){

    if (high < low)  return -1;

    // Find mid
    int mid = low + (high - low)/2; /*(low + high)/2;*/

    // Check if element (mid+1) is minimum element. Consider
    // the cases like {3, 4, 5, 1, 2}
    if (A[mid] == B)
       return mid;

    // Check if mid itself is minimum element
    if (A[mid] < B)
       return binary(A,mid+1, high,B);

    // Decide whether we need to go to left half or right half
    if (A[mid] > B)
       return binary(A,low, mid-1,B);
}

int search(const vector<int> &A, int B) {

    int minElementIndex = findMinIndex(A,0,A.size()-1);

    //cout << minElementIndex << "\n";

    if (B==A[minElementIndex]){
        return minElementIndex;
    }

    if (minElementIndex==0){
        return binary(A,1,A.size()-1,B);
    }

    if (minElementIndex==A.size()-1){
        return binary(A,0,A.size()-2,B);
    }

    if (A[A.size()-1]>=B){
        return binary(A,minElementIndex+1,A.size()-1,B);
    }

    if (A[0]<=B){
        return binary(A,0,minElementIndex-1,B);
    }


}

int main(){

    vector <int> A = {101, 103, 106, 109, 158, 164, 182, 187, 202, 205, 2, 3, 32, 57, 69, 74, 81, 99, 100};
    cout << min_element(A.begin(),A.end()) - A.begin();
    //cout << search(A,202);
    //361746042
}
