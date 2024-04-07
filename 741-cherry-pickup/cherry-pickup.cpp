class Solution {
public:
    int help(int r1,int c1,int r2,int c2,int n,vector<vector<int>>& grid,vector<vector<vector<vector<int>>>>& dp){
        if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;
        if(r1==n-1 && c1==n-1) return grid[r1][c1];
        if(r2==n-1 && c2==n-1) return grid[r2][c2];
        if(dp[r1][c1][r2][c2]!=-1) return dp[r1][c1][r2][c2];
        int cherries=0;
        if(r1==r2 && c1==c2) cherries=grid[r1][c1];
        else cherries=grid[r1][c1]+grid[r2][c2];

        cherries+=max(max(help(r1+1,c1,r2+1,c2,n,grid,dp),help(r1+1,c1,r2,c2+1,n,grid,dp)),
                      max(help(r1,c1+1,r2+1,c2,n,grid,dp),help(r1,c1+1,r2,c2+1,n,grid,dp)));
        return dp[r1][c1][r2][c2]=cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        return max(0,help(0,0,0,0,n,grid,dp));
    }
};