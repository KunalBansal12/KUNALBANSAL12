class Solution {

    private:
    bool fun(int mid,vector<int>&nums,int k){
        int yet=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]<=mid){
                i+=2;
                yet++;
            }
            else{
                i++;
            }
            if(yet>=k){
                return true;
            }
        }
        return false;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int si=1,ei=1e9;
        int ans=0;
        while(si<=ei){
            int mid=si+(ei-si)/2;
            bool check=fun(mid,nums,k);
            if(check){
                ans=mid;
                ei=mid-1;
            }
            else{
                si=mid+1;
            }
        }
        return ans;
    }

    // TLE
    // int help(int ind,int k,vector<int>& nums,vector<vector<int>>& dp){
    //     if(k==0) return INT_MIN;
    //     if(ind>=nums.size() && k>0) return INT_MAX;
    //     if(dp[ind][k]!=INT_MAX) return dp[ind][k];
    //     int ans=INT_MAX;
    //     ans=min(ans,help(ind+1,k,nums,dp));
    //     ans=min(ans,max(nums[ind],help(ind+2,k-1,nums,dp)));
    //     return dp[ind][k]=ans;
    // }

    // int minCapability(vector<int>& nums, int k) {
    //     int n=nums.size();
    //     vector<vector<int>> dp(n,vector<int>(k+1,INT_MAX));
    //     return help(0,k,nums,dp);
    // }
};