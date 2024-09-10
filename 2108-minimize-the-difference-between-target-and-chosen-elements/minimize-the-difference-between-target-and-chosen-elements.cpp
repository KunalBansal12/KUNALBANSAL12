class Solution {
public:
    void help(int row,int sum,int target,vector<vector<int>>& dp,vector<vector<int>>& mat,int& ans){
        if(row==mat.size()){
            ans=min(ans,abs(target-sum));
            return;
        }
        else if(dp[row][sum]!=-1){
            return;
        }
        for(int i=0;i<mat[0].size();i++){
            sum+=mat[row][i];
            help(row+1,sum,target,dp,mat,ans);
            sum-=mat[row][i];
        }
        dp[row][sum]=0;
        return;
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> dp(n,vector<int>(n*70+1,-1));
        int ans=INT_MAX;
        help(0,0,target,dp,mat,ans);
        return ans;
    }
};