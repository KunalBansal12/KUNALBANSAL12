class Solution {
public:
    int mod=1000000007;

    int help(int i,int steps,int n,vector<vector<int>>& dp){
        if(steps==0 && i==0) return 1;
        else if(steps==0 && i!=0) return 0;
        if(dp[steps][i]!=-1) return dp[steps][i];
        long long a=0,b=0,c=0;
        if(i!=0) a=help(i-1,steps-1,n,dp);
        if(i<n-1) b=help(i+1,steps-1,n,dp);
        c=help(i,steps-1,n,dp);
        return dp[steps][i]=(a+b+c)%mod;
    }

    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps+1,vector<int>(min(steps,arrLen),-1));
        return help(0,steps,arrLen,dp);
    }
};