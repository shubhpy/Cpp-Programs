/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {

    vector<int> res;

    stack<TreeNode*> st;

    TreeNode* t = A;
    TreeNode* p;
    bool done = false;

    while(!done){
        if (t==NULL){
            if (!st.empty()){
                p  = st.top();
                res.push_back(p->val);
                st.pop();
                t = p->right;
            }
            else{
                done = true;
            }
        }
        else{
            st.push(t);
            t = t->left;
        }
    }

    return res;


    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
