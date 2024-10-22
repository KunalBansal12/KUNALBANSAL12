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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            int n=q.size();
            long long sum=0;
            for(int i=0;i<n;i++){
                TreeNode* f=q.front();
                q.pop();
                sum+=f->val;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            ans.push_back(sum);
        }
        sort(ans.begin(),ans.end());
        if(k>ans.size()) return -1;
        return ans[ans.size()-k];
    }
};