/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode *root,int sum){
        if(root->left==NULL && root->right==NULL){
            return sum*10+root->val;
        }
        int x=0,y=0;
        if(root->left!=NULL)
        x=helper(root->left,10*sum+root->val);
        if(root->right!=NULL)
        y=helper(root->right,10*sum+root->val);
        int z=x+y;
        return z;
    }

    int sumNumbers(TreeNode* root) {
        return helper(root,0);
    }
};