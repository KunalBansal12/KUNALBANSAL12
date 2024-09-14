class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=0;
        for(auto it:nums) maxi=max(maxi,it);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi){
                int size=0;
                while(i<nums.size() && nums[i]==maxi){
                    size++;
                    i++;
                }
                ans=max(ans,size);
            }
        }
        return ans;
    }
};