class Solution {
public:
    int largestCombination(vector<int>& nums) {
        int n=nums.size();
        vector<int> bits(30,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<24;j++){
                bits[j]+=nums[i]%2;
                nums[i]=nums[i]/2;
            }
        }
        int ans=0;
        for(int i=0;i<30;i++) ans=max(ans,bits[i]);
        return ans;
    }
};