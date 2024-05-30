class Solution {
public:
    void help(vector<int>& nums,int i,int target,vector<vector<int>>& ans,vector<int>& ans1){
        if(target==0){
            ans.push_back(ans1);
            return;
        }
        else if(i==nums.size()) return;
        help(nums,i+1,target,ans,ans1);
        ans1.push_back(nums[i]);
        if(target-nums[i]>=0) help(nums,i,target-nums[i],ans,ans1);
        ans1.pop_back();
        return; 
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> ans1;
        help(nums,0,target,ans,ans1);
        return ans;
    }
};