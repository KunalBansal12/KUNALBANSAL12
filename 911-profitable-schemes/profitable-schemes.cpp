class Solution {
public:
    int help(int n,int mp,int ind,vector<int>& group,vector<int>& profit,vector<vector<vector<int>>>& dp){
        if(n<0) return 0;
        if(mp<0) mp=0;
        if(ind>=group.size()){
            if(mp<=0) return 1;
            else return 0;
        }
        if(dp[ind][n][mp]!=-1) return dp[ind][n][mp];
        long long take=help(n-group[ind],mp-profit[ind],ind+1,group,profit,dp);
        int nottake=help(n,mp,ind+1,group,profit,dp);
        int ans=(take+nottake)%1000000007;
        return dp[ind][n][mp]=ans;
    }

    int profitableSchemes(int n, int mp, vector<int>& group, vector<int>& profit) {
        int m=group.size();
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(mp+1,-1)));
        int ans=help(n,mp,0,group,profit,dp);
        return ans;
    }
};