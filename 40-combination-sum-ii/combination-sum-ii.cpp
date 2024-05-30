class Solution {
public:
    void help(vector<int>& nums,int i,vector<vector<int>>& ans,vector<int>& a1,int target){
        if(target==0){
            ans.push_back(a1);
            return;
        }
        else if(i==nums.size()){
            return;
        }
        int j=i;
        while(j<nums.size() && nums[j]==nums[i]){
            j++;
        }
        help(nums,j,ans,a1,target);
        a1.push_back(nums[i]);
        if(target-nums[i]>=0) help(nums,i+1,ans,a1,target-nums[i]);
        a1.pop_back();
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> ans1;
        help(nums,0,ans,ans1,target);
        return ans;
    }
};