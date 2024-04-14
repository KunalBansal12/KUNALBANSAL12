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
    int help(TreeNode* root){
        if(root==NULL) return 0;
        int ans=0;
        if(root->left){
            if(root->left->left==NULL && root->left->right==NULL){
                ans+=root->left->val;
                ans+=help(root->left);
            }
            else ans+=help(root->left);
        }
        ans+=help(root->right);
        return ans;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return 0;
        return help(root);
    }
};