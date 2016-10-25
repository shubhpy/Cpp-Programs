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

void print_Inorder(struct node* root){
    if (root==NULL){
            return;
    }
    print_Inorder(root->left);
    cout << root->data << " ";
    print_Inorder(root->right);
}

void print_Postorder(struct node* root){
    if (root==NULL){
            return;
    }
    print_Postorder(root->left);
    print_Postorder(root->right);
    cout << root->data << " ";
}

void print_Preorder(struct node* root){
    if (root==NULL){
            return;
    }
    cout << root->data << " ";
    print_Preorder(root->left);
    print_Preorder(root->right);
}

struct node* Search(struct node*root,int item){
    if (root==NULL || root->data == item ){
            return root;
    }
    else if(root->data > item){
        return Search(root->left,item);
    }
    else if (root->data < item){
        return Search(root->right,item);
    }
}

int minValue(struct node* root){
    if (root==NULL){
        return INT_MIN;
    }
    else if (root->left == NULL){
        return root->data;
    }
    else{
        return minValue(root->left);
    }
}

int main()
{
  /*create root*/
  struct node *root = newNode(10);
  root = insert(root,6);
  root = insert(root,11);
  root = insert(root,5);
root = insert(root,8);
  root = insert(root,7);
  root = insert(root,9);
  root = insert(root,12);
root = insert(root,16);
  root = insert(root,14);
  root = insert(root,13);
  root = insert(root,15);
root = insert(root,17);

print_Inorder(root);

cout << "\n" << minValue(root);

  return 0;
}
