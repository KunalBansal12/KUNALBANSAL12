class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size()/3;
        int maj1,maj2,count1=0,count2=0;
        for(int i=0;i<nums.size();i++){
            if(maj1==nums[i]) count1++;
            else if(maj2==nums[i]) count2++;
            else if(count1==0){
                count1++;
                maj1=nums[i];
            }
            else if(count2==0){
                count2++;
                maj2=nums[i];
            }
            else{
                count1--;
                count2--;
            }
        }
        count1=0,count2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maj1) count1++;
            else if(nums[i]==maj2) count2++;
        }
        vector<int> ans;
        if(count1>n) ans.push_back(maj1);
        if(count2>n) ans.push_back(maj2);
        return ans;
    }
};