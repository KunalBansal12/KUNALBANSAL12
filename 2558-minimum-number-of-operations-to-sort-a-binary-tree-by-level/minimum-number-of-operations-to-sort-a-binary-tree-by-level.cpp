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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(q.size()){
            int n=q.size();
            vector<int> help1;
            vector<int> help2;
            unordered_map<int,int> map;
            for(int i=0;i<n;i++){
                TreeNode* front=q.front();
                q.pop();
                help1.push_back(front->val);
                help2.push_back(front->val);
                map[front->val]=i;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            sort(help1.begin(),help1.end());
            for(int i=0;i<n;i++){
                if(help1[i]!=help2[i]){
                    int need=help2[i];
                    swap(help2[i],help2[map[help1[i]]]);
                    map[need]=map[help1[i]];
                    ans++;
                }
            }
        }
        return ans;
    }
};