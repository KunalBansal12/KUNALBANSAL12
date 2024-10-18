class Solution {
public:
    int help(int ind,int t,vector<int>& cost,vector<int>& time,vector<vector<int>>& dp){
        if(t>=cost.size()) return 0;
        else if(ind>=cost.size()) return 1000000000;
        if(dp[ind][t]!=-1) return dp[ind][t];
        int a=cost[ind]+help(ind+1,t+1+time[ind],cost,time,dp);
        int b=help(ind+1,t,cost,time,dp);
        return dp[ind][t]=min(a,b);
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n=cost.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return help(0,0,cost,time,dp);
    }
};