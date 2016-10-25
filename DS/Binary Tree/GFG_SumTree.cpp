/*  Tree node
struct Node
{
    int data;
    struct Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
bool isSumTree(struct Node* root)
{
     // Your code here
     int ls,rs;

     if (root==NULL || (root->left==NULL && root->right==NULL)){
         return 1;
     }
     if (isSumTree(root->left) && isSumTree(root->right)){
        if(root->left == NULL)
            ls = 0;
        else if(root->left->left==NULL && root->left->right==NULL)
            ls = root->left->data;
        else
            ls = 2*(root->left->data);

        // Get the sum of nodes in right subtree
        if(root->right == NULL)
            rs = 0;
        else if(root->right->left==NULL && root->right->right==NULL)
            rs = root->right->data;
        else
            rs = 2*(root->right->data);

        /* If root's data is equal to sum of nodes in left
           and right subtrees then return 1 else return 0*/
        return(root->data == ls + rs);
     }
     return 0;

}
