/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void help(Node* root,Node* node,unordered_map<int,Node*>& vis){
        vis[root->val]=root;
        for(int i=0;i<(node->neighbors.size());i++){
            if(vis[node->neighbors[i]->val]){
                root->neighbors.push_back(vis[node->neighbors[i]->val]);
                continue;
            }
            Node* newnode=new Node(node->neighbors[i]->val);
            root->neighbors.push_back(newnode);
            help(newnode,node->neighbors[i],vis);
        }
        return;
    }

    Node* cloneGraph(Node* node) {
        if(node==NULL) return node;
        unordered_map<int,Node*> vis;
        Node* root=new Node(node->val);
        help(root,node,vis);
        return root;
    }
};