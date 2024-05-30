class Solution {
public:
    void help(vector<int>& nums,int i,vector<vector<int>>& ans,vector<int>& a1){
        if(i==nums.size()){
            ans.push_back(a1);
            return;
        }
        int j=i;
        while(j<nums.size() && nums[j]==nums[i]){
            j++;
        }
        help(nums,j,ans,a1);
        a1.push_back(nums[i]);
        help(nums,i+1,ans,a1);
        a1.pop_back();
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> ans1;
        help(nums,0,ans,ans1);
        return ans;
    }
};