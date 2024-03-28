class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int ans=0,si=0,len=0;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
            len++;
            if(map[nums[i]]>k){
                while(si<i){
                    map[nums[si]]--;
                    len--;
                    si++;
                    if(nums[si-1]==nums[i]) break;
                }
            }
            ans=max(ans,len);
        }
        return ans;
    }
};