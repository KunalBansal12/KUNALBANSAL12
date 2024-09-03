class Solution {
public:
    long long help(vector<int>& nums,int x,vector<vector<long long>>& dp,int ind,int odd){
        if(ind==nums.size()-1){
            if(nums[ind]%2==odd) return nums[ind];
            else return max(0,nums[ind]-x);
        }
        else if(dp[ind][odd]!=-1){
            return dp[ind][odd];
        }
        long long ans=max(help(nums,x,dp,ind+1,odd),-x+help(nums,x,dp,ind+1,1-odd));
        if(nums[ind]%2==odd) ans=ans+nums[ind];
        return dp[ind][odd]=ans;
    }

    long long maxScore(vector<int>& nums, int x) {
        vector<vector<long long>> dp(nums.size(),vector<long long>(2,-1));
        return help(nums,x,dp,0,nums[0]%2); 
    }
};