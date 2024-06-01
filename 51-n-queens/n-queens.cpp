class Solution {
public:
    void help(int si,int n,vector<vector<string>>& ans,vector<string>& ans1,unordered_map<int,int>& col,unordered_map<int,int>& diag1,unordered_map<int,int>& diag2){
        if(si==n){
            ans.push_back(ans1);
            return;
        }
        for(int i=0;i<n;i++){
            if(!col[i] && !diag1[si-i] && !diag2[i+si]){
                col[i]=1;
                diag1[si-i]=1;
                diag2[i+si]=1;
                ans1[si][i]='Q';
                help(si+1,n,ans,ans1,col,diag1,diag2);
                ans1[si][i]='.';
                col[i]=0;
                diag1[si-i]=0;
                diag2[i+si]=0;
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> ans1;
        string one="";
        for(int i=0;i<n;i++) one+='.';
        for(int i=0;i<n;i++) ans1.push_back(one);
        unordered_map<int,int> col,diag1,diag2;
        help(0,n,ans,ans1,col,diag1,diag2);
        return ans;
    }
};