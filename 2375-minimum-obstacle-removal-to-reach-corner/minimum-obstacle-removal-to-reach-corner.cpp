class Solution {
public:
    vector<vector<int>> d={{0,1},{0,-1},{1,0},{-1,0}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
        dp[0][0]=0;
        q.push({0,0});
        while(q.size()){
            auto t=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int newx=t.first+d[i][0],newy=t.second+d[i][1];
                if(newx<0 || newx>=n || newy<0 || newy>=m) continue;
                if(dp[t.first][t.second]+grid[newx][newy]>=dp[newx][newy]) continue;
                dp[newx][newy]=dp[t.first][t.second]+grid[newx][newy];
                q.push({newx,newy});
            }
        }
        return dp[n-1][m-1];
    }
};