class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int one=0,two=0,three=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1) one++;
            else if(nums[i]==2) two=max(one,two)+1;
            else if(nums[i]==3) three=max(one,max(two,three))+1;
        }
        return nums.size()-max(one,max(two,three));
    }
};