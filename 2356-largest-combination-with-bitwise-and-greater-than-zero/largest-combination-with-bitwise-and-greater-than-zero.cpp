class Solution {
public:
    int largestCombination(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        vector<int> bits(24,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<24;j++){
                bits[j]+=nums[i]%2;
                nums[i]=nums[i]/2;
                if(i==n-1) ans=max(ans,bits[j]);
            }
        }
        // for(int i=0;i<24;i++) ans=max(ans,bits[i]);
        return ans;
    }
};