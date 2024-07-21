class Solution {
public:
    int help(int ind,int sum,vector<int>& nums,vector<vector<int>>& dp){
        if(sum<0) return 0;
        else if(sum==0) return 1;
        else if(ind==nums.size()) return 0;
        else if(dp[ind][sum]!=-1) return dp[ind][sum];
        int not_take=help(ind+1,sum,nums,dp);
        int take=help(ind+1,sum-nums[ind],nums,dp);
        return dp[ind][sum]=take | not_take;
    }

    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2) return false;
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        return help(0,sum/2,nums,dp);
    }
};