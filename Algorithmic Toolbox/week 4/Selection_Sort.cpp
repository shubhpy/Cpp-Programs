#include <iostream>
#include <vector>
#include <cmath>

using std::vector;
using std::cin;
using std::cout;

int selectionSort(vector<int>& x,int n){
    for(int i=0;i<n;i++){
        int minIndex = i;
        int temp=0;
        for(int j=i+1;j<n;j++){
            if (x[minIndex]>x[j]){
            minIndex=j;
            }
        }
        temp = x[i];
        x[i]=x[minIndex];
        x[minIndex]=temp;
    }
    for(int i=0;i<n;i++){
        cout << x[i] << " ";
    }

}


int main() {
    int n;
    cin >> n;
    vector<int> x(n+1);
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    selectionSort(x,n);


    return 0;
}


