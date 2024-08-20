class Solution {
public:
    int rec(int i,int m,vector<int>&piles,int n,vector<vector<int>>&dp){
        if(i==n) return 0;
        if(dp[i][m]!=-1) return dp[i][m];
        int ans=INT_MIN;
        int x = min(n,i+(2*m));
        int sum=0;
        for(int j=i;j<x;j++){
            sum+=piles[j];
            ans = max(ans,sum-rec(j+1,max(m,j-i+1),piles,n,dp));
        }
        return dp[i][m]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int diff = rec(0,1,piles,n,dp);
        int sum=0;
        for(auto it:piles){
            sum+=it;
        }
        return (sum+diff)/2;
    }
};