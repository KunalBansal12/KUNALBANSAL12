#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<=3) return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++){
            ll sum=nums[i];
            if(i!=0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size()-2;j++){
                if(j!=i+1 && nums[j]==nums[j-1]) continue;
                ll sum1=sum+nums[j];
                int l=j+1,r=nums.size()-1; 
                while(l<r){
                    ll n=sum1+nums[l]+nums[r];
                    if(n>(ll)target) r--;
                    else if(n<(ll)target) l++;
                    else{
                        vector<int> ans1;
                        ans1.push_back(nums[i]);
                        ans1.push_back(nums[j]);
                        ans1.push_back(nums[l]);
                        ans1.push_back(nums[r]);
                        ans.push_back(ans1);
                        while(l<r && nums[l]==nums[l+1]) l++;
                        while(l<r && nums[r]==nums[r-1]) r--;
                        l++,r--;
                    }
                }
            }
        }
        return ans;
    }
};