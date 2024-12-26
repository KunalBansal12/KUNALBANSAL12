class Solution {
public:
    void helper(vector<int>& nums,int target,int& ans,int si,int sum){
        if(si==nums.size()){
            if(target==sum) ans++;
            return;
        }
        helper(nums,target,ans,si+1,sum+nums[si]);
        helper(nums,target,ans,si+1,sum-nums[si]);
        return;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int ans=0;
        helper(nums,target,ans,0,0);
        return ans;
    }
};