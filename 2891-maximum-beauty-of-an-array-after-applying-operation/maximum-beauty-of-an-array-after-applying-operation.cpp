class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0,j=0,ans=0;
        while(j<nums.size()){
            while(j<nums.size() && nums[j]-nums[i]<=2*k) j++;
            ans=max(ans,j-i);
            i++;
        }
        return ans;
    }
};