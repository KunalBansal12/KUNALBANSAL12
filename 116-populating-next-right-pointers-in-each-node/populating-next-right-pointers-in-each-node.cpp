/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void help(Node* root1,Node* root2){
        if(root2==NULL) return;
        root1->next=root2;
        help(root1->right,root2->left);
        root1=connect(root1);
        root2=connect(root2);
        return;
    }

    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        help(root->left,root->right);
        return root;
    }
};