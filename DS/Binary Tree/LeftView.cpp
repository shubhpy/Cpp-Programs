// C program to print left view of Binary Tree
#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *left, *right;
};

// A utility function to create a new Binary Tree node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
/* A binary tree node
struct Node
{
    int data;
    struct Node* left, * right;
}; */

// A wrapper over leftViewUtil()
void leftView(struct node *root)
{
    if(root==NULL)return;
	vector<struct node*>cur;
	cur.push_back(root);

	while(cur.size()>0){
		vector<struct node*>temp;
		cout << (cur[0])->data << " ";
		for(int i=0;i<cur.size();i++){
			if(cur[i]->left!=NULL){
				temp.push_back(cur[i]->left);
			}
			if(cur[i]->right!=NULL){
				temp.push_back(cur[i]->right);
			}
		}
		cur = temp;
	}
}

// Recursive function to print left view of a binary tree.
void leftViewUtil(struct node *root, int level, int *max_level)
{
    // Base Case
    if (root==NULL)  return;

    // If this is the first node of its level
    if (*max_level < level)
    {
        printf("%d\t", root->data);
        *max_level = level;
    }

    // Recur for left and right subtrees
    leftViewUtil(root->left, level+1, max_level);
    leftViewUtil(root->right, level+1, max_level);
}

// A wrapper over leftViewUtil()
void leftView(struct node *root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}

// Driver Program to test above functions
int main()
{
    struct node *root = newNode(12);
    root->left = newNode(10);
    root->right = newNode(30);
    root->right->left = newNode(25);
    root->right->right = newNode(40);

    leftView(root);

    return 0;
}
