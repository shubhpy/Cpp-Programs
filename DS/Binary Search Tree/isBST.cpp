
#include<iostream>
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

struct node* insert(struct node* root,int data){
    if (root==NULL){
        return newNode(data);
    }
    //No Duplicates

    else if(data < root->data){
        root->left = insert(root->left,data);
    }
    else if (data > root->data) {
        root->right = insert(root->right,data);
    }
    return root;
    }

int isBST(struct node* node,int min, int max) {

     if (node==NULL) return(true);
    // false if this node violates the min/max constraint
    if (node->data<min || node->data>max) return(false);
    // otherwise check the subtrees recursively,
    // tightening the min or max constraint
    return isBST(node->left, min, node->data) && isBST(node->right, node->data+1, max);
}

int main()
{
  /*create root*/
  struct node *root;
  root = insert(root,10);
  root = insert(root,6);
  root = insert(root,11);
root = insert(root,8);
  root = insert(root,7);
  root = insert(root,9);
  root = insert(root,12);
root = insert(root,16);
  root = insert(root,14);
  root = insert(root,13);
  root = insert(root,15);
root = insert(root,17);

cout << isBST(root,-1000,2000);


  return 0;
}
