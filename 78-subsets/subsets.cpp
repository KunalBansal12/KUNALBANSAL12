class Solution {
public:
    vector<vector<int>> helper(vector<int>& nums,int n,vector<vector<int>> ans){
        if(n==0){
            vector<int> base;
            ans.push_back(base);
            return ans;
        }
        else{
            int a=nums[n-1];
            ans=helper(nums,n-1,ans);
            int x=ans.size();
            for(int i=0;i<x;i++){
                vector<int> base;
                base=ans[i];
                base.push_back(a);
                ans.push_back(base);
            }
            return ans;
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans=helper(nums,nums.size(),ans);
        return ans;
    }
};