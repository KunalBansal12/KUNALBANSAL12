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
    void helper(TreeNode* root,int l,int& val,int& max_l){
        if(root==NULL) return;
        if(l>max_l){
            val=root->val;
            max_l=l;
        }
        helper(root->left,l+1,val,max_l);
        helper(root->right,l+1,val,max_l);
    }

    int findBottomLeftValue(TreeNode* root) {
        if(!root->left && !root->right) return root->val;
        int max_l=0,val=0;
        helper(root,0,val,max_l);
        return val;
    }
};