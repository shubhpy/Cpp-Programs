#include <iostream>
#include <vector>
#include <cmath>

using std::vector;
using std::cin;
using std::cout;

int binarySearch(vector<int>& x,int low, int high,int key){

    if (high<low){
            return low;
        }
    double mid = std::floor(low  + (high-low)/2);

    if (x[mid]==key){
        return mid+1;
        }
    else if( key < x[mid]){
        return binarySearch(x,low,mid-1,key);
        }
    else{
        return binarySearch(x,mid+1,high,key);
        }
}


int main() {
    int low;
    int high;
    int key;
    cout << "Designed to set low from enter low then high then array then the key \n" ;
    cin >> low >> high;
    vector<int> x(high+1);
    for(int i=0;i<high;i++){
        cin >> x[i];
    }
    for(int i=0;i<high;i++){
        cout << i+1 << " ";
    }

        for(int i=0;i<high;i++){
        cin >> key ;
        cout << binarySearch(x,low,high,key) << "\n";
    }


    return 0;
}

