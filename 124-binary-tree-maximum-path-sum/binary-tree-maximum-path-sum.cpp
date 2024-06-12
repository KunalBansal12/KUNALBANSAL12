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
    int helper(TreeNode* root,int& ans){
        if(root==NULL) return 0;
        int l=max(0,helper(root->left,ans));
        int r=max(0,helper(root->right,ans));
        int sum=l+r+root->val;
        ans=max(ans,sum);
        return max(l,r)+root->val;
    }

    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        int x=helper(root,ans);
        return ans;
    }
};