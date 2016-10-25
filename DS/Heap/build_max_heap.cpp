#include<iostream>
#include<vector>
#include<limits.h>
#define maxSize 13

int parent(int i);

using namespace std;

void printArray(vector<int>& H,int &size_H){
    for(int j=0;j<=size_H;j++){
        cout << H[j] << " ";
        }
    cout << " \n";
    }

void swap(vector<int>& H,int i1,int i2){
    int temp = H[i1];
    H[i1] = H[i2];
    H[i2] = temp;
    }

void siftup_max(vector<int>& H,int i){
    while (i>0 && H[parent(i)] < H[i]){
        swap(H,parent(i),i);
        i=parent(i);
        }
    }

int parent(int i){
    return (i-1)/2;
    }
int leftchild(int i){
    return 2*i + 1;
    }
int rightchild(int i){
    return 2*i + 2;
    }

void siftdown_max(vector<int>& H,int &size_H,int i){
    int maxindex = i;
    int l = leftchild(i);
    if (l<=size_H && H[l] > H[maxindex])
        maxindex = l;
    int r =rightchild(i);
    if (r<=size_H && H[r] > H[maxindex])
        maxindex = r;

    if (i!=maxindex){
        swap(H,i,maxindex);
        siftdown_max(H,size_H,maxindex);
        }
    }

void Insert(vector<int>& H,int &size_H,int p){
    if (size_H==maxSize)
        cout << "Error in Insert" << " \n";

    size_H++;
    H[size_H] = p;
    siftup_max(H,size_H);
    printArray(H,size_H);
    }

int ExtractMax(vector<int>& H,int &size_H){
    int result = H[0];
    H[0] = H[size_H];
    size_H--;
    siftdown_max(H,size_H,0);
    return result;
    }

int getMax(vector<int>& H){
    return H[0];
    }


void Build_Max_Heap(vector<int>& H,int &size_H){
    for(int j=(size_H-1)/2;j>=0;j--){
        siftdown_max(H,size_H,j);
        }
    }

void changepriority(vector<int>& H,int &size_H,int i,int p){

    int oldp = H[i];
    H[i] = p;
    if (p >oldp){
        siftup_max(H,i);
    }
    else{
        siftdown_max(H,size_H,i);
    }
    }


void deletekey(vector<int>& H,int &size_H,int i){

    changepriority(H,size_H,i,INT_MAX);
    ExtractMax(H,size_H);

    }

void HeapSort(vector<int>& H,int &size_H){

    int temp_size = size_H;

    Build_Max_Heap(H,size_H);
    printArray(H,size_H);
    for(int j=0;j<temp_size;j++){
        swap(H,0,size_H);
        size_H--;
        siftdown_max(H,size_H,0);
        cout << "step  " << j << "\n";
        printArray(H,temp_size);
    }
    }

int main(){
   // int size_H;
   // cin >> size_H;

   vector<int> H(maxSize);
   H[0] = 4;
   H[1] = 10;
   H[2] = 3;
   H[3] = 5;
   H[4] = 1;

   int size_H = 4;
   int temp = size_H;

   HeapSort(H,size_H);

   printArray(H,temp);
   // size_H--;
    //for(int j=0;j<=size_H;j++){
    //    cin >> H[j];
    //    }



/*
    int size_H = -1;
    Insert(H,size_H,3);
    Insert(H,size_H,2);
    deletekey(H,size_H,1);
    Insert(H,size_H,15);
    Insert(H,size_H,5);
    Insert(H,size_H,4);
    Insert(H,size_H,45);
    cout << ExtractMax(H,size_H) << " \n";
    printArray(H,size_H);
    cout << getMax(H) << " \n";
    changepriority(H,size_H,2, 1);
    printArray(H,size_H);
    cout << getMax(H);
*/
    //printArray(H,size_H);
    //Insert(H,size_H,32);
    //cout << ExtractMax(H,size_H) << "\n";

    //Build_Max_Heap(H,size_H);

    //printArray(H,size_H);

    return 0;
        }

