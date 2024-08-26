/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void help(vector<int>& ans,Node* root){
        if(root->children.size()==0){
            ans.push_back(root->val);
            return;
        }
        for(int i=0;i<root->children.size();i++){
            help(ans,root->children[i]);
        }
        ans.push_back(root->val);
        return;
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        help(ans,root);
        return ans;
    }
};