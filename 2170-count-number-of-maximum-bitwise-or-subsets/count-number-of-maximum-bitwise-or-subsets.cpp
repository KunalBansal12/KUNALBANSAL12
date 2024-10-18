class Solution {
public:
    int sum(int i,vector<int>& nums,int maxi,int curr){
        if(i==nums.size()){
            if(maxi==curr) return 1;
            return 0;
        }
        return sum(i+1,nums,maxi,curr)+sum(i+1,nums,maxi,curr|nums[i]);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0;
        for(auto it:nums) maxi=maxi|it;
        return sum(0,nums,maxi,0);
    }
};