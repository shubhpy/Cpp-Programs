#include<vector>
#include<iostream>

using namespace std;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      j++;
    swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}


int main(){

    vector<int> arr(3);
    arr[0]=5;
    arr[1]=58;
    arr[2]=10;
    arr[3]=10;
    int n=4;
    int k=3;
    int count = 0;

    randomized_quick_sort(arr, 0, n - 1);
    int mul=arr[0];
    for(int i=0;i<k;i++){
        count+=n*mul;
        mul=arr[i+1]-arr[i];
        n--;
        }

    cout << count;


    }
