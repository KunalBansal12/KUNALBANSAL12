class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            if(nums[i]!=i+1 && nums[nums[i]-1]==nums[i]){
                i++;
                continue;
            }
            else if(nums[i]!=i+1){
                swap(nums[i],nums[nums[i]-1]);
            }
            else if(nums[i]==i+1){
                i++;
            }
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};