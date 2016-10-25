#include<iostream>
#include<vector>
#include<limits.h>
#define maxSize 100000

int parent(int i);

using namespace std;

void swap(vector<int>& H,int i1,int i2){
    int temp = H[i1];
    H[i1] = H[i2];
    H[i2] = temp;
    }

void siftup_min(vector<int>& H,int i){
    while (i>0 && H[parent(i)] > H[i]){
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

void siftdown_min(vector<int>& H,int &size_H,int i){
    int minindex = i;
    int l = leftchild(i);
    if (l<=size_H && H[l] < H[minindex])
        minindex = l;
    int r =rightchild(i);
    if (r<=size_H && H[r] < H[minindex])
        minindex = r;

    if (i!=minindex){
        swap(H,i,minindex);
        siftdown_min(H,size_H,minindex);
        }
    }

void Insert(vector<int>& H,int &size_H,int p){
    if (size_H==maxSize)
        cout << "Error in Insert" << " \n";

    size_H++;
    H[size_H] = p;
    siftup_min(H,size_H);
    //printArray(H,size_H);
    }

void removeMin(vector<int>& H,int &size_H){
    int result = H[0];
    H[0] = H[size_H];
    size_H--;
    siftdown_min(H,size_H,0);
    //return result;
    }

int getMin(vector<int>& H){
    return H[0];
    }


int main(){

    vector<int> H(maxSize);
    vector<pair<string,long long int> > ans;
    int size_H = -1;
    long long int n;
    string o;
    long long int a;
    cin << n;
    for(int i=0;i<n;i++){
        cin >> o;
        if (o=="insert"){
            cin >> a;
            Insert(H,size_H,a);
            ans.push_back(make_pair("insert",a));
        }
        else if (o == "removeMin"){
                removeMin(H,size_H);
                ans.push_back(make_pair("removeMin",0));
        }
        else if(o=="getMin"){
            cin >> a;
            if (getMin(H)==a){
                ans.push_back(make_pair("getMin",a));
            }
            else if (getMin(H) < a){
                while(getMin(H) < a){
                    removeMin(H,size_H);
                    ans.push_back(make_pair("removeMin",0));
                }

                Insert(H,size_H,a);
                ans.push_back(make_pair("insert",a));
                ans.push_back(make_pair("getMin",a));
            }
            else{
                Insert(H,size_H,a);
                ans.push_back(make_pair("insert",a));
                ans.push_back(make_pair("getMin",a));

            }
        }
    }

    cout << ans.size() << "\n";
    for(int i=0;i<ans.size();i++){
        if (ans[i].first=="removeMin"){
            cout << ans[i].first << "\n";
        }
        else{
            cout << ans[i],first << " " <<  ans.second << "\n";
        }
    }

    return 0;
        }

