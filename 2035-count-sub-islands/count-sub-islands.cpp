class Solution {
public:
    bool help(int i,int j,vector<vector<int>>& grid1,vector<vector<int>>& grid2,vector<vector<int>>& vis){
        if(i<0 || i>=grid1.size() || j<0 || j>=grid1[0].size()) return true;
        else if(grid2[i][j]==0) return true;
        else if(grid1[i][j]!=grid2[i][j]) return false;
        else if(vis[i][j]) return true;
        vis[i][j]=1;
        bool ans=true;
        ans=ans & help(i+1,j,grid1,grid2,vis);
        ans=ans & help(i,j+1,grid1,grid2,vis);
        ans=ans & help(i-1,j,grid1,grid2,vis);
        ans=ans & help(i,j-1,grid1,grid2,vis);
        return ans;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(),m=grid1[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==0) vis[i][j]=1;
                else if(vis[i][j]) continue;
                else{
                    bool a1=help(i,j,grid1,grid2,vis);
                    ans+=(a1? 1:0);
                }
            }
        }
        return ans;
    }
};