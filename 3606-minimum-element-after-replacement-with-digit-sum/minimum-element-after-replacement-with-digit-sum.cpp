class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int num=0;
            while(nums[i]){
                num+=nums[i]%10;
                nums[i]=nums[i]/10;
            }
            mini=min(mini,num);
        }
        return mini;
    }
};