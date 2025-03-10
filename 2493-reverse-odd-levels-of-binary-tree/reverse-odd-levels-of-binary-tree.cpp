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
    void rev(TreeNode* root1,TreeNode* root2,int level){
        if(root1==NULL && root2==NULL) return;
        if(level%2!=0){
            int temp=root1->val;
            root1->val=root2->val;
            root2->val=temp;
        }
        rev(root1->left,root2->right,level+1);
        rev(root1->right,root2->left,level+1);
        return;
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        rev(root->left,root->right,1);
        return root;
    }
};