class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==0) continue;
            else if(nums[i]==nums[i+1]){
                nums[i]*=2;
                nums[i+1]=0;
            }
            else continue;
        }
        int i=0,j=0;
        while(j<nums.size()){
            while(i<nums.size() && nums[i]!=0){
                i++;
            }
            if(i>=j) j=i+1;
            if(j<nums.size() && nums[j]!=0){
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
            else j++;
        }
        return nums;
    }
};