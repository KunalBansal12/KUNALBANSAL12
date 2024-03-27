class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int si=0,pr=1,ans=0;
        for(int i=0;i<nums.size();i++){
            pr*=nums[i];
            if(pr<k) ans+=i-si+1;
            else{
                while(si<i && pr>=k){
                    pr=pr/nums[si];
                    si++;
                }
                if(pr<k) ans+=i-si+1;
            }
        }
        return ans;
    }
};