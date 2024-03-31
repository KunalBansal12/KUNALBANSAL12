class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int count=0,num=0;
            bool flag=false;
            for(int j=i;j<n;j++){
                num=num | nums[j];
                count++;
                if(num>=k){
                    flag=true;
                    break;
                }
            }
            if(flag) ans=min(ans,count);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};