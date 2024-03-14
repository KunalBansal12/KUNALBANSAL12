class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> map;
        int count=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int diff=sum-goal;
            map[sum]++;
            if(diff==0){
                if(goal==0) count+=map[sum];
                else count++,count+=map[0];
            }
            else if(diff>0){
                if(goal==0) count+=map[diff]-1;
                else count+=map[diff];
            }
        }
        return count;
    }
};