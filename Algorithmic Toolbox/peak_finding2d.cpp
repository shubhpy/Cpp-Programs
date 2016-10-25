#include<iostream>
#include<vector>

using namespace std;

int maximum(int *arr,int r,int c,int column){
    int temp_index=0;
    int temp=0;
    for (int i = 0; i < r; i++){
        if (*((arr+i*c) + column) > temp){
            temp_index=i;
            temp = *((arr+i*c) + column);
            }
    }
    return temp_index;
    }

int peak_finder(int *arr,int r,int c,int start_column ,int end_column){
    int column = start_column + (end_column-start_column)/2;
    int max_index = maximum((int *)arr,r,c,column);
    int max_in_column = *((arr+max_index*c) + column);

    if (end_column==start_column){
        return max_in_column;
    }
    else{
    if (max_in_column < *((arr+max_index*c) + column -1)){
        return peak_finder((int *)arr,r,c,start_column,column-1);
        }
    else if (max_in_column < *((arr+max_index*c) + column+1)){
        return peak_finder((int *)arr,r,c,column+1,end_column);
        }
    else {
        return max_in_column;
        }
    }


}

int main()
{
    int n,m;
    cin>> n >> m;
    int arr[n][m];
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
            }
        }
    cout << peak_finder((int *)arr,n,m,0,m-1);

    //cout<< maximum((int *)arr,n,m,0) << " \n";
    //cout<< maximum((int *)arr,n,m,1) << " \n";
    //cout<< maximum((int *)arr,n,m,2) << " \n";
    return 0;
}
