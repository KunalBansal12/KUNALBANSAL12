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
class BSTIterator {
public:
    TreeNode* root;
    int count;
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root1) {
        root=root1;
        TreeNode* temp=root;
        while(temp){
            st.push(temp);
            temp=temp->left;
        }
    }

    void putt(TreeNode* t){
        while(t){
            st.push(t);
            t=t->left;
        }
    }
    
    int next() {
        int k=st.top()->val;
        TreeNode* t=st.top();
        st.pop();
        putt(t->right);
        return k;
    }
    
    bool hasNext() {
        if(st.size()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */