class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // vector<vector<int>> ans2;
        // unordered_map<int,int> map;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        // if(nums[0]==nums[nums.size()-1]){
        //     if(nums[0]==0){
        //         vector<int> ans3;
        //         ans3.push_back(0);
        //         ans3.push_back(0);
        //         ans3.push_back(0);
        //         ans2.push_back(ans3);
        //         return ans2;
        //     }
        //     else return ans2;
        // }
        // for(int i=0;i<nums.size();i++){
        //     map[nums[i]]++;
        // }
        for(int i=0;i<nums.size()-2;i++){
            int sum=nums[i];
            // map[nums[i]]--;
            if(i!=0 && nums[i]==nums[i-1]) continue;
            int l=i+1,r=nums.size()-1;
            while(l<r){
                int s=nums[i]+nums[l]+nums[r];
                if(s>0) r--;
                else if(s<0) l++;
                else{
                    vector<int> ans1;
                    ans1.push_back(nums[i]);
                    ans1.push_back(nums[l]);
                    ans1.push_back(nums[r]);
                    ans.push_back(ans1);
                    while(l<r && nums[l]==nums[l+1]) l++;
                    while(l<r && nums[r]==nums[r-1]) r--;
                    l++,r--;
                }
            }
            // unordered_map<int,int> map1;
            // for(int k=i+1;k<nums.size();k++) map1[nums[k]]++;
            // for(int j=i+1;j<nums.size()-1;j++){
            //     map1[nums[j]]--;
            //     if(j!=i+1 && nums[j]==nums[j-1]) continue;
            //     int sum1=sum+nums[j];
            //     if(map1[-sum1]!=0){
            //         vector<int> ans1;
            //         ans1.push_back(sum);
            //         ans1.push_back(nums[j]);
            //         ans1.push_back(-sum1);
            //         ans.push_back(ans1);
            //     }
            // }
        }
        return ans;
    }
};