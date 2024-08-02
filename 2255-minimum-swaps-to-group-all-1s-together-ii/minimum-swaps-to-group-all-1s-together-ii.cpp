class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int one=0,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==1) one++;
        }
        int ans=INT_MAX;
        int i=0,j=0,z=0;
        for(i=0;i<one;i++){
            if(nums[i]==0) z++;
        }
        ans=min(ans,z);
        for(int k=0;k<n-1;k++){
            int l=(i+k)%n;
            if(nums[l]==0) z++;
            if(nums[j]==0) z--;
            j++;
            ans=min(ans,z);
        }
        return ans;
    }
};