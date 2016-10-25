#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int match(vector<int> &mat, vector<int> &mag){
    int count = 0;
    for(int i=0;i<9;i++){
            count+=abs(mat[i] - mag[i]);
    }

    return count;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    vector<int> mat(9);
    for(int i=0;i<9;i++){
        cin >> mat[i];
    }

    int magic1[] = {4,9,2,3,5,7,8,1,6};
    //int magic2[3][3] = {{2,7,6},{9,5,1},{4,3,8}};
    //int magic3[3][3] = {{6,1,8},{7,5,3},{2,9,4}};
    //int magic4[3][3] = {{8,3,4},{1,5,9},{6,7,2}};

    vector<int> mag;

    mag.assign(magic1,magic1+9);

    vector<int> resv(4);
    resv[1] = match(mat,mag);
    //resv[2] = match(mat,magic2);
    //resv[3] = match(mat,magic3);
    //resv[4] = match(mat,magic4);

    cout << *min_element(resv.begin(),resv.end());

    return 0;
}
