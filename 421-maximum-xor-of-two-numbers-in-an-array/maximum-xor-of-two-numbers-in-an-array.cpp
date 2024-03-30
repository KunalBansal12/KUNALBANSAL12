class Node{
    public:
    Node* links[2];
    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }
    void push(int bit,Node* node){
        links[bit]=node;
    }
    Node* get(int bit){
        return links[bit];
    }
};

class Trie{
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int nums){
        Node* temp=root;
        for(int i=31;i>=0;i--){
            int bit=(nums>>i) & 1;
            if(!temp->containsKey(bit)){
                temp->push(bit,new Node());
            }
            temp=temp->get(bit);
        }
    }
    int getMax(int num){
        Node* temp=root;
        int maxi=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(temp->containsKey(1-bit)){
                maxi=maxi | (1<<i);
                temp=temp->get(1-bit);
            }
            else{
                temp=temp->get(bit);
            }
        }
        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto i:nums) trie.insert(i);
        int maxi=0;
        for(auto i:nums) maxi=max(maxi,trie.getMax(i));
        return maxi;
    }
};