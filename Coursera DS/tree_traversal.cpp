#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void in_order(vector <int>& key,vector <int>& left,vector <int>& right,int key_i,int left_index,int right_index) {
    if (left_index == right_index){
        cout << key_i << " ";
        return;
        }
    else{
        if (left_index!=-1){
        in_order(key,left,right,key[left_index],left[left_index],right[left_index]);
        }
        cout << key_i << " ";
        if (right_index!=-1){
        in_order(key,left,right,key[right_index],left[right_index],right[right_index]);

        }
        }
  }

void pre_order(vector <int>& key,vector <int>& left,vector <int>& right,int key_i,int left_index,int right_index) {
    if (left_index == right_index){
        cout << key_i << " ";
        return;
        }
    else{
        cout << key_i << " ";
        if (left_index!=-1){
        pre_order(key,left,right,key[left_index],left[left_index],right[left_index]);
        }
        if (right_index!=-1){
        pre_order(key,left,right,key[right_index],left[right_index],right[right_index]);
        }
        }
  }

void post_order(vector <int>& key,vector <int>& left,vector <int>& right,int key_i,int left_index,int right_index) {
    if (left_index == right_index){
        cout << key_i << " ";
        return;
        }
    else{
        if (left_index!=-1){
        post_order(key,left,right,key[left_index],left[left_index],right[left_index]);
        }
        if (right_index!=-1){
        post_order(key,left,right,key[right_index],left[right_index],right[right_index]);
        }
        cout << key_i << " ";
        }
  }

int main() {
    int n;
    vector <int> key;
    vector <int> left;
    vector <int> right;

    cin >> n;
    key.resize(n);
    left.resize(n);
    right.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> key[i] >> left[i] >> right[i];
    }

  in_order(key,left,right,key[0],left[0],right[0]);
  cout << "\n";
  pre_order(key,left,right,key[0],left[0],right[0]);
  cout << "\n";
  post_order(key,left,right,key[0],left[0],right[0]);
  //print(t.post_order());
  return 0;
}

