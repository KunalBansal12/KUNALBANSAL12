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

// TLE
//  class Solution {
// public:
//     long long help(TreeNode* root,int lev){
//         if(root==NULL){
//             if(lev>=1) return INT_MAX;
//             return 0;
//         }
//         long long a=INT_MAX,b=INT_MAX,c=INT_MAX;
//         if(lev==2){
//             a=1+help(root->left,0)+help(root->right,0);
//             return a;
//         }
//         else if(lev==0){
//             a=1+help(root->left,0)+help(root->right,0);
//             b=help(root->left,1)+help(root->right,1);
//             return min(a,b);
//         }
//         else if(lev==1){
//             a=1+help(root->left,0)+help(root->right,0);
//             b=help(root->left,2)+help(root->right,1);
//             c=help(root->left,1)+help(root->right,2);
//             return min(a,min(b,c));
//         }
//         return 0;
//     }

//     int minCameraCover(TreeNode* root) {
//         return min(1+help(root->left,0)+help(root->right,0),
//                    min(help(root->left,1)+help(root->right,0),
//                    help(root->left,0)+help(root->right,1)));
//     }
// };
class Solution {
public:
    int ans=0;
    int help(TreeNode* root){
        if(root==NULL) return 2;
        int left=help(root->left);
        int right=help(root->right);
        if(left==0 || right==0){
            ans++;
            return 1;
        }
        if(left==1 || right==1) return 2;
        return 0;
    }

    int minCameraCover(TreeNode* root) {
        int res=0;
        if(root->left==NULL && root->right==NULL) return 1;
        return (help(root) < 1 ? 1 : 0) + ans;
    }
};