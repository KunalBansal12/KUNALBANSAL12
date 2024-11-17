class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),q=queries.size();
        vector<int> diff(n+1,0);
        for(int i=0;i<q;i++){
            int l=queries[i][0];
            int r=queries[i][1];
            diff[l]-=1;
            diff[r+1]+=1;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=diff[i];
            if(nums[i]+sum>0) return false;
        }
        return true;
    }
};