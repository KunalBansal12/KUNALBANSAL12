class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int ans=-1;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            if(map[-nums[i]]) ans=max(ans,abs(nums[i]));
            map[nums[i]]++;
        }
        return ans;
    }
};