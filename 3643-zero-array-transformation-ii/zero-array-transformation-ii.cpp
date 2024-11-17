class Solution {
public:
    bool check(int mid,vector<int>& nums,vector<vector<int>>& queries){
        vector<int> diff(nums.size()+1,0);
        for(int i=0;i<mid;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            int val=queries[i][2];
            diff[l]-=val;
            diff[r+1]+=val;
        }
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=diff[i];
            if(nums[i]+sum>0) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans=INT_MAX;
        int low=0,q=queries.size(),high=q,n=nums.size();
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(mid,nums,queries)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};