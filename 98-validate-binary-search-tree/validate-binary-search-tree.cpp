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
#define ll long long
class Solution {
public:
    bool help(TreeNode* root,ll maxi,ll mini){
        if(root==NULL) return true;
        else if((ll)(root->val)>=maxi || (ll)(root->val)<=mini) return false;
        bool l=help(root->left,(ll)(root->val),mini);
        bool r=help(root->right,maxi,(ll)(root->val));
        return l&&r;
    }

    bool isValidBST(TreeNode* root) {
        return help(root,((ll)(INT_MAX))+1,(ll)(INT_MIN)-1);
    }
};