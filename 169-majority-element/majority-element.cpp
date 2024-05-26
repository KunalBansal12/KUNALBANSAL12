class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj=INT_MIN;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(maj==INT_MIN && count==0){
                maj=nums[i];
                count=1;
            }
            else if(maj==nums[i]){
                count++;
            }
            else if(maj!=nums[i]){
                if(count>1){
                    count--;
                }
                else if(count==1){
                    maj=INT_MIN;
                    count=0;
                }
            }
        }
        return maj;
    }
};