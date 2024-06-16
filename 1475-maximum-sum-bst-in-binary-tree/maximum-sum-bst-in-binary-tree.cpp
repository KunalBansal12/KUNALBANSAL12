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
 #define pp pair<int,pair<int,int>>
class Solution {
public:
    pp help(TreeNode* root,int& sum){
        if(root==NULL) return {0,{INT_MAX,INT_MIN}};
        pp l=help(root->left,sum);
        pp r=help(root->right,sum);
        if(l.first==INT_MIN) return {INT_MIN,{INT_MIN,INT_MIN}};
        if(r.first==INT_MIN) return {INT_MIN,{INT_MIN,INT_MIN}};
        int s=l.first+r.first+root->val;
        if(root->val>l.second.second && root->val<r.second.first){
            sum=max(sum,s);
            return {s,{min(root->val,l.second.first),max(root->val,r.second.second)}};
        }
        return {INT_MIN,{INT_MIN,INT_MIN}};
    }

    int maxSumBST(TreeNode* root) {
        int sum=0;
        pp temp=help(root,sum);
        return sum;
    }
};