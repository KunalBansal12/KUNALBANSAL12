class Node{
    public:
    Node* links[26];
    bool flag=false;
};

class Trie{
    public:
    Node* root;
    Trie(){
        root=new Node();
    }
    void insert(string s){
        Node* temp=root;
        for(int i=0;i<s.length();i++){
            if(temp->links[s[i]-'a']==NULL){
                temp->links[s[i]-'a']=new Node();
            }
            temp=temp->links[s[i]-'a'];
        }
        temp->flag=true;
    }
};

class Solution {
public:
    void help(int i,int j,string a,vector<vector<int>>& vis,Node* temp,set<string>& ans,vector<vector<char>>& board){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return;
        if(vis[i][j]) return;
        if(temp->links[board[i][j]-'a']==NULL) return;
        // cout<<a<<endl;
        temp=temp->links[board[i][j]-'a'];
        a+=board[i][j];
        if(temp->flag) ans.insert(a);
        vis[i][j]=1;
        int r[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            help(i+r[k],j+r[(k+1)%4],a,vis,temp,ans,board);
        }
        vis[i][j]=0;
        return;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(int i=0;i<words.size();i++) trie.insert(words[i]);
        int n=board.size(),m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        set<string> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                help(i,j,"",vis,trie.root,ans,board);
            }
        }
        vector<string> ans1;
        for(auto it:ans) ans1.push_back(it);
        return ans1;
    }
};