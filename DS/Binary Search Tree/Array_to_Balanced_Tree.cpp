#include <iostream>
#include<vector>
#include <limits.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data){
  // Allocate memory for new node
  struct node* node = (struct node*)malloc(sizeof(struct node));

  // Assign data to this node
  node->data = data;

  // Initialize left and right children as NULL
  node->left = NULL;
  node->right = NULL;
  return(node);
}

void preorder(struct node* root){
    if (!root){
        return;
    }
    cout << root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}

struct node* fun(int arr[],int start,int end,struct node* root){

    if(start==end){
        return newNode(arr[start]);
    }
    int n = (end-start)/2;
    root = newNode(arr[start+n]);
    root->left = fun(arr,start+n+1,end,root);
    root->right = fun(arr,start,start+n-1,root);

    return root;
    }


int main(){

    int T,N,C,i;
    cin >> T;
    for(i=0;i<T;i++){
        cin >> N;
        int arr[N];
        for(int j=0;j<N;j++){
            cin >> C;
            arr[j] = C;
        }
        int sizeArr = sizeof(arr)/sizeof(arr[0]);
        struct node * root ;
        struct node * root2 = fun(arr,0,sizeArr-1,root);
        preorder(root2);
        cout << "\n";

    }
    //int arr[] = {7,6,5,4,3,2,1};

    return 0;
    }
