#include<iostream>
#include<vector>
#define maxSize 13

int parent(int i);

using namespace std;

void printArray(vector<int>& H,int size_H){
    for(int j=0;j<=size_H;j++){
        cout << H[j] << " ";
        }
    cout << " \n";
    }

void Swap(vector<int>& H,int i1,int i2){
    int temp = H[i1];
    H[i1] = H[i2];
    H[i2] = temp;
    }

void siftUp(vector<int>& H,int i){
    while (i>0 && H[parent(i)] < H[i]){
        Swap(H,parent(i),i);
        i=parent(i);
        }}
int parent(int i){
    return (i-1)/2;
    }
int leftchild(int i){
    return 2*i + 1;
    }
int rightchild(int i){
    return 2*i + 2;
    }

void siftDown(vector<int>& H,int size_H,int i){
    int maxindex = i;
    int l = leftchild(i);
    if (l<=size_H && H[l] > H[maxindex])
        maxindex = l;
    int r =rightchild(i);
    if (r<=size_H && H[r] > H[maxindex])
        maxindex = r;

    if (i!=maxindex){
        Swap(H,i,maxindex);
        siftDown(H,size_H,maxindex);
        }
    }

void Insert(vector<int>& H,int size_H,int p){
    if (size_H==maxSize)
        cout << "Error in Insert" << " \n";

    size_H++;
    H[size_H] = p;
    siftUp(H,size_H);
    printArray(H,size_H);
    }

int ExtractMax(vector<int>& H,int size_H){
    int result = H[0];
    H[0] = H[size_H];
    size_H--;
    siftDown(H,size_H,0);
    return result;
    }

void BuildHeap(vector<int>& H,int size_H){
    for(int j=(size_H-1)/2;j>-1;j--){
        siftDown(H,size_H,j);
        }
    }

void HeapSort(vector<int>& H,int size_H){
    BuildHeap(H,size_H);
    printArray(H,size_H);
    int temp_size = size_H;
    for(int j=0;j<temp_size+1;j++){
        Swap(H,0,size_H);
        size_H--;
        siftDown(H,size_H,0);
        }
    }

int main(){
    vector<int> H(20);
    int size_H = 8;
    H[0]=7;
    H[1]=9;
    H[2]=10;
    H[3]=6;
    H[4]=8;
    H[5]=5;
    H[6]=1;
    H[7]=2;
    H[8]=3;
    printArray(H,size_H);
    //Insert(H,size_H,32);
    //cout << ExtractMax(H,size_H) << "\n";
    BuildHeap(H,size_H);

    printArray(H,size_H);
        }

/*
    H[0]=42;
    H[1]=29;
    H[2]=18;
    H[3]=14;
    H[4]=7;
    H[5]=18;
    H[6]=12;
    H[7]=11;
    H[8]=5;
*/
