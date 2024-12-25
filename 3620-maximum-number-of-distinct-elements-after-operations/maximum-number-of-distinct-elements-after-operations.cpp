class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=1,num=nums[0]-k+1;
        for(int i=1;i<nums.size();i++){
            if(num>=nums[i]-k && num<=nums[i]+k){
                ans++;
                num++;
            }
            else if(num<nums[i]-k){
                ans++;
                num=nums[i]-k+1;
            }
        }
        return ans;
    }
};