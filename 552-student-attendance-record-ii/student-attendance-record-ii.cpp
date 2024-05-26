class Solution {
public:
    int help(vector<vector<vector<int>>>& dp,int n,int a,int l){
        if(n==0) return 1;
        long long ans=0;
        if(dp[n][a][l]!=-1) return dp[n][a][l];
        ans+=help(dp,n-1,a,0);
        ans%=1000000007;
        if(a==0) ans+=help(dp,n-1,a+1,0);
        ans%=1000000007;
        if(l<=1) ans+=help(dp,n-1,a,l+1);
        return dp[n][a][l]=ans%1000000007;
    }

    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return help(dp,n,0,0);
    }
};