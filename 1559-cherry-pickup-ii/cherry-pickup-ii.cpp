class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return help(0,0,m-1,n,m,grid,dp);
    }

    int help(int r,int c1,int c2,int n,int m,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(c1<0 || c1>=m || c2<0 || c2>=m) return -10000000;
        int val=grid[r][c1]+grid[r][c2];
        if(c1==c2) val-=grid[r][c1];
        if(r==n-1) return dp[r][c1][c2]=val;
        if(dp[r][c1][c2]!=-1) return dp[r][c1][c2];
        int l[]={-1,0,1};
        int ans=val;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                ans=max(ans,val+help(r+1,c1+l[i],c2+l[j],n,m,grid,dp));
            }
        }
        return dp[r][c1][c2]=ans;
    }
};