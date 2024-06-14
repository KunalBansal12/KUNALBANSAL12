class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int uniq=nums[0];
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1] || nums[i]<=uniq){
                uniq++;
                ans+=uniq-nums[i];
            }
            if(uniq<nums[i]) uniq=nums[i];
        }
        return ans;
    }
};