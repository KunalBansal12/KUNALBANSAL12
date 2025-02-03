class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1,num=1,inc=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1] && inc!=1){
                ans=max(ans,num);
                num=2;
                inc=1;
            }
            else if(nums[i]>nums[i-1]){
                num++;
            }
            else if(nums[i]<nums[i-1] && inc!=-1){
                ans=max(ans,num);
                num=2;
                inc=-1;
            }
            else if(nums[i]<nums[i-1]){
                num++;
            }
            else if(nums[i]==nums[i-1]){
                num=1;
                inc=0;
            }
            ans=max(ans,num);
        }
        // ans=max(ans,num);
        return ans;
    }
};