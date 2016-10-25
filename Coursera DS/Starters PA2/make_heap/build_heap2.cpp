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
        }
    }

void siftUp_Higher_parent(vector<int>& H,int i){
    while (i>0 && H[parent(i)] > H[i]){
        cout << parent(i) <<  " " << i <<  "\n";
        Swap(H,parent(i),i);
        i=parent(i);
        }
    }

int siftUp_Higher_parent_No_print(vector<int>& H,int i){
    int count1=0;
    while (i>0 && H[parent(i)] > H[i]){
        count1++;
        Swap(H,parent(i),i);
        i=parent(i);
        }
    return count1;
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

void siftDown(vector<int>& H,int size_H,int i){
    int maxindex = i;
    int l = leftchild(i);
    if (l<=size_H && H[l] > H[maxindex])
        maxindex = l;
    int r =rightchild(i);
    if (r<=size_H && H[r] > H[maxindex])
        maxindex = r;

    if (i!=maxindex){
        cout << i <<  " " << maxindex <<  "\n";
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

void Build_Max_Heap(vector<int>& H,int size_H){
    for(int j=(size_H-1)/2;j>-1;j--){
        siftDown(H,size_H,j);
        }
    }

void Build_Min_Heap(vector<int>& H,int size_H){
    for(int j=size_H;j>-1;j--){
        siftUp_Higher_parent(H,j);
        }
    }

int Build_Min_Heap_no_print(vector<int>& H,int size_H){
    int count=0;
    for(int j=size_H;j>-1;j--){
        count+=siftUp_Higher_parent_No_print(H,j);
        }
    return count;
    }

void HeapSort(vector<int>& H,int size_H){
    Build_Max_Heap(H,size_H);
    int temp_size = size_H;
    for(int j=0;j<temp_size;j++){
        Swap(H,0,size_H);
        size_H--;
        siftDown(H,size_H,0);
        }
    }

int main(){
    int size_H;
    cin >> size_H;
    vector<int> H(size_H);
    size_H--;
    for(int j=0;j<=size_H;j++){
        cin >> H[j];
        }
    vector<int> G(size_H);
    for(int j=0;j<=size_H;j++){
        G[j] = H[j];
        }
    //printArray(H,size_H);
    //Insert(H,size_H,32);
    //cout << ExtractMax(H,size_H) << "\n";
    Build_Max_Heap(H,size_H);

    //cout << Build_Min_Heap_no_print(H,size_H) << "\n";

    //Build_Min_Heap(G,size_H);

    //printArray(H,size_H);
        }

