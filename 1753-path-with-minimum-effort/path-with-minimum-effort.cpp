class Solution {
public:
#define p tuple<int,int,int>
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        vector<vector<int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        priority_queue<p,vector<p>,greater<p>> pq;
        pq.push({0,0,0});
        dp[0][0]=0;
        while(pq.size()){
            auto [a,b,c]=pq.top();
            pq.pop();
            for(int k=0;k<4;k++){
                int x=b+dir[k][0],y=c+dir[k][1];
                if(x>=0 && y>=0 && x<n && y<m){
                    int diff=abs(heights[b][c]-heights[x][y]);
                    diff=max(diff,dp[b][c]);
                    if(diff<dp[x][y]){
                        dp[x][y]=diff;
                        pq.push({diff,x,y});
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};