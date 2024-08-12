class KthLargest {
private:
    int target;
    TreeNode* tree_root;
    void insert_BST(int val) {
        TreeNode* prev = nullptr;
        TreeNode* root = tree_root;
        while (root) {
            prev=root;

            if (root->val<val) {
                root=root->right;
            }
            else {
                root=root->left;
            }
        }
        TreeNode* tmp = new TreeNode(val);

        if (prev) {
            if (prev->val<val) {
                prev->right=tmp;
            }
            else {
                prev->left=tmp;
            }
        }
        else {
            tree_root=tmp;
        }
        return;
    }
    void search_BST(TreeNode*& res, TreeNode* root,int& k) {

        if (root) {
            search_BST(res,root->right,k);
            if (k==0) {
                if (!res) {
                    res=root;
                }
                return;
            }
            --k;
            search_BST(res,root->left,k);
        }

        return;


    }
public:
    KthLargest(int k, vector<int>& nums) :target(k),tree_root(nullptr) {
        if (!nums.empty()) {
            for (const auto& n:nums) {
                insert_BST(n);
            }
        }
    }
    
    int add(int val) {
        insert_BST(val);
        TreeNode* root=tree_root;
        int k=target-1;
        TreeNode* res = nullptr;

        search_BST(res,root,k);

        if (res) {
            return res->val;
        }
        return -10001;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */