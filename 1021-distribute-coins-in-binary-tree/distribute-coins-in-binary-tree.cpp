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
    pair<int,int> help(TreeNode* root,int req,int xtra,int& ans){
        // if(root==NULL) return {0,0};
        if(root->val>1) xtra=(root->val-1);
        else if(root->val==0) req=1;

        if(root->left){
            pair<int,int> l=help(root->left,0,0,ans);
            ans+=l.first+l.second;
            if(req==1){
                if(l.first>=1){
                    req+=l.first;
                }
                else if(l.second>=1){
                    req=0;
                    xtra+=l.second-1;
                }
            }
            else if(xtra>=1){
                if(l.second>=1){
                    xtra+=l.second;
                }
                else if(l.first>=1){
                    if(l.first>=xtra){
                        req+=l.first-xtra;
                        xtra=0;
                    }
                    else if(l.first<xtra){
                        xtra=xtra-l.first;
                    }
                }
            }
            else{
                req+=l.first;
                xtra+=l.second;
            }
        }
        
        if(root->right){
            pair<int,int> r=help(root->right,0,0,ans);
            ans+=r.first+r.second;
            if(req>=1){
                if(r.first>=1){
                    req+=r.first;
                }
                else if(r.second>=1){
                    if(r.second>=req){
                        xtra=r.second-req;
                        req=0;
                    }
                    else if(r.second<req){
                        req-=r.second;
                    }
                }
            }
            else if(xtra>=1){
                if(r.second>=1){
                    xtra+=r.second;
                }
                else if(r.first>=1){
                    if(r.first>=xtra){
                        req+=r.first-xtra;
                        xtra=0;
                    }
                    else if(r.first<xtra){
                        xtra=xtra-r.first;
                    }
                }
            }
            else{
                req+=r.first;
                xtra+=r.second;
            }
        }
        return {req,xtra};
    }

    int distributeCoins(TreeNode* root) {
        int ans=0;
        pair<int,int> fin= help(root,0,0,ans);
        return ans;
    }
};