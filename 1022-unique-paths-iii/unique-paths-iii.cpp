class Solution {
public:
    int help(int i,int j,int ei,int ej,int num,vector<vector<int>>& vis,vector<vector<int>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return 0;
        if(ei<0 || ei>=grid.size() || ej<0 || ej>=grid[0].size()) return 0;
        if(vis[i][j]) return 0;
        if(grid[i][j]==-1) return 0;
        else if(grid[i][j]==2){
            if(num==0) return 1;
            else return 0;
        }
        vis[i][j]=1;
        if(grid[i][j]==0) num--;
        int r[]={0,1,0,-1};
        int ans=0;
        for(int k=0;k<4;k++){
            ans+=help(i+r[k],j+r[(k+1)%4],ei,ej,num,vis,grid);
        }
        vis[i][j]=0;
        return ans;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int si=0,sj=0,ei=0,ej=0,num=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) si=i,sj=j;
                else if(grid[i][j]==2) ei=i,ej=j;
                else if(grid[i][j]==0) num++;
            }
        }
        vector<vector<int>> vis(n,vector<int>(m,0));
        return help(si,sj,ei,ej,num,vis,grid);
    }
};