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
    TreeNode* help(TreeNode* root){
        if(root==NULL) return NULL;
        TreeNode* l=help(root->left);
        TreeNode* r=help(root->right);
        if(!l && !r) return root;
        else if(!l) return r;
        else if(!r){
            root->right=root->left;
            root->left=NULL;
            return l;
        }
        else{
            TreeNode* r1=root->right;
            root->right=root->left;
            root->left=NULL;
            l->right=r1;
            return r;
        }
        return l;
    }

    void flatten(TreeNode* root) {
        TreeNode* temp=help(root);
        return;
    }
};