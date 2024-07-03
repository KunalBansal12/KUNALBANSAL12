class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()<=4) return 0;
        else{
            int n=nums.size();
            int mini=INT_MAX;
            mini=min(mini,nums[n-4]-nums[0]);
            mini=min(mini,nums[n-3]-nums[1]);
            mini=min(mini,nums[n-2]-nums[2]);
            mini=min(mini,nums[n-1]-nums[3]);
            return mini;
        }
    }
};