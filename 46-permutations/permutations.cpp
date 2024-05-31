class Solution {
public:
    void help(vector<int>& nums,int si,vector<vector<int>>& ans,vector<int>& ans1){
        if(si==nums.size()) ans.push_back(ans1);
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=11){
                ans1.push_back(nums[i]);
                nums[i]=11;
                help(nums,si+1,ans,ans1);
                nums[i]=ans1[ans1.size()-1];
                ans1.pop_back();
            }
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans1;
        vector<vector<int>> ans;
        help(nums,0,ans,ans1);
        return ans;
    }
};