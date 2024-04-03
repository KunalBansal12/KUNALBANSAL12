class Solution {
public:
    bool help(int i,int j,int ind,vector<vector<int>>& vis,vector<vector<char>>& board,string word){
        if(ind==word.length()) return true;
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return false;
        if(board[i][j]!=word[ind]) return false;
        if(vis[i][j]) return false;
        int r[]={0,-1,0,1};
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            bool check=help(i+r[k],j+r[(k+1)%4],ind+1,vis,board,word);
            if(check) return true;
        }
        vis[i][j]=0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool check=help(i,j,0,vis,board,word);
                if(check) return true;
            }
        }
        return false;
    }
};