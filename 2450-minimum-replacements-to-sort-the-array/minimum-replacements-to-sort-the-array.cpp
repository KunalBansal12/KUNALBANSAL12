class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans=0;
        int n=nums.size(),mini=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=mini){
                mini=nums[i];
                continue;
            }
            else{
                int k=nums[i]/mini;
                ans+=k-1;
                if(nums[i]%mini){
                    ans++;
                    mini=nums[i]/(k+1);
                }
            }
        }
        return ans;
    }
};