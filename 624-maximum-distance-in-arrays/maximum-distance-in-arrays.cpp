class Solution {
public:
    int maxDistance(vector<vector<int>>& nums) {
        int mini1=INT_MAX,mini2=INT_MAX,ind1=-1,ind2=-1;
        int maxi1=INT_MIN,maxi2=INT_MIN,ind3=-1,ind4=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i][0]<=mini1){
                ind2=ind1;
                mini2=mini1;
                mini1=nums[i][0];
                ind1=i;
            }
            else if(nums[i][0]<=mini2){
                ind2=i;
                mini2=nums[i][0];
            }
            int n=nums[i].size();
            if(nums[i][n-1]>=maxi1){
                ind4=ind3;
                maxi2=maxi1;
                ind3=i;
                maxi1=nums[i][n-1];
            }
            else if(nums[i][n-1]>=maxi2){
                ind4=i;
                maxi2=nums[i][n-1];
            }
        }
        if(ind1!=ind3){
            return maxi1-mini1;
        }
        return max(maxi1-mini2,maxi2-mini1);
    }
};