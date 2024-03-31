class Node{
    public:
    Node* links[2];
    bool containsKey(int num){
        return (links[num]!=NULL);
    }
    void put(int num,Node* node){
        links[num]=node;
    }
    Node* get(int num){
        return links[num];
    }
};

class Trie{
    Node* root;
    public:
    Trie(){ root=new Node();}
    void insert(int num){
        Node* temp=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(!temp->containsKey(bit)){
                temp->put(bit,new Node());
            }
            temp=temp->get(bit);
        }
    }
    int getMax(int num){
        Node* temp=root;
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i) & 1;
            if(temp->containsKey(!bit)){
                maxNum=(1<<i) | maxNum;
                temp=temp->get(!bit);
            }
            else{
                temp=temp->get(bit);
            }
        }
        return maxNum;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> q(queries.size(),vector<int>(3,0));
        for(int i=0;i<queries.size();i++){
            q[i][0]=queries[i][1];
            q[i][1]=queries[i][0];
            q[i][2]=i;
        }
        sort(q.begin(),q.end());
        vector<int> ans(queries.size(),0);
        Trie trie;
        int k=0;
        for(int i=0;i<q.size();i++){
            while(k<nums.size() && nums[k]<=q[i][0]){
                trie.insert(nums[k]);
                k++;
            }
            if(k==0) ans[q[i][2]]=-1;
            else ans[q[i][2]]=trie.getMax(q[i][1]);
        }
        return ans;
    }
};