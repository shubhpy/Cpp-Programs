#include<iostream>
#include<vector>
#include <limits.h>

using namespace std;

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node* newNode(char data){
  // Allocate memory for new node
  struct node* node = (struct node*)malloc(sizeof(struct node));
  // Assign data to this node
  node->data = data;

  // Initialize left and right children as NULL
  node->left = NULL;
  node->right = NULL;
  return(node);
}

struct node * BuildTreeInPre(char in[],char pre[],int FromIn,int ToIn){
    static int preIdx = 0;

    if(FromIn > ToIn)
        return NULL;

    char x = pre[preIdx++];

    struct node * tnode = newNode(x);

    if(FromIn == ToIn)
        return tnode;

    int xinInorder;
    for(int i=FromIn;i<=ToIn;i++){
        if (in[i]==x){
            xinInorder = i;
        }
    }
    tnode->left  = BuildTreeInPre(in,pre,FromIn,xinInorder-1);
    tnode->right  = BuildTreeInPre(in,pre,xinInorder+1,ToIn);
    return tnode;
    }

struct node * BuildTreeInPost(char in[],char post[],int FromIn,int ToIn){
    static int postIdx = ToIn;
    if(FromIn > ToIn)
        return NULL;

    char x = post[postIdx];
    postIdx--;

    struct node * tnode = newNode(x);

    if(FromIn == ToIn)
        return tnode;

    int xinInorder;
    for(int i=FromIn;i<=ToIn;i++){
        if (in[i]==x){
            xinInorder = i;
        }
    }
    tnode->right  = BuildTreeInPost(in,post,xinInorder+1,ToIn);
    tnode->left  = BuildTreeInPost(in,post,FromIn,xinInorder-1);
    return tnode;
    }

void printInorder(struct node* node)
{
  if (node == NULL)
     return;

  /* first recur on left child */
  printInorder(node->left);

  /* then print the data of node */
  cout << node->data << " ";

  /* now recur on right child */
  printInorder(node->right);
}

void printPreorder(struct node* node)
{
  if (node == NULL)
     return;

cout << node->data << " ";

  /* first recur on left child */
  printPreorder(node->left);

  /* now recur on right child */
  printPreorder(node->right);
}


void printPostorder(struct node* node)
{
  if (node == NULL)
     return;

  /* first recur on left child */
  printPostorder(node->left);

  /* now recur on right child */
  printPostorder(node->right);

  cout << node->data << " ";
}

int main()
{
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  char post[] = {'D', 'E', 'B', 'F', 'C','A'};

  struct node *root = BuildTreeInPre(in,pre,0,5);
  printPostorder(root);

  cout << "\n";

  struct node *root2 = BuildTreeInPost(in,post,0,5);
  printPreorder(root2);

  return 0;
}
