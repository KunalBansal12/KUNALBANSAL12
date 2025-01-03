class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum=0,num=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            num+=nums[i];
            long long k=sum-num;
            if(num>=k) ans++;
        }
        return ans;
    }
};