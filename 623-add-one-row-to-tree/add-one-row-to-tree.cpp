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
    void add(TreeNode* root,int val,int depth){
        if(root==NULL) return;
        if(depth==2){
            TreeNode* temp1=root->left;
            TreeNode* temp2=root->right;
            TreeNode* n1=new TreeNode(val);
            TreeNode* n2=new TreeNode(val);
            root->left=n1;
            root->right=n2;
            n1->left=temp1;
            n2->right=temp2;
            return;
        }
        addOneRow(root->left,val,depth-1);
        addOneRow(root->right,val,depth-1);
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* n=new TreeNode(val);
            n->left=root;
            return n;
        }
        add(root,val,depth);
        return root;
    }
};