// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<int> dp(n,1);
//         int ans=1;
//         for(int i=1;i<n;i++){
//             for(int j=i-1;j>=0;j--){
//                 if(nums[i]>nums[j]) dp[i]=max(dp[i],dp[j]+1);
//             }
//             ans=max(ans,dp[i]);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the first element >= x
                *it = x; // Replace that number with x
            }
        }
        return sub.size();
    }
};