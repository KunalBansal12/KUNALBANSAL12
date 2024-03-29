class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0,n=nums.size();
        int maxi=0,si=0,big=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==maxi) big++;
            if(big>=k){
                while(si<=i && big>=k){
                    ans+=n-i;
                    if(nums[si]==maxi) big--;
                    si++;
                }
            }
        }
        return ans;
    }
};