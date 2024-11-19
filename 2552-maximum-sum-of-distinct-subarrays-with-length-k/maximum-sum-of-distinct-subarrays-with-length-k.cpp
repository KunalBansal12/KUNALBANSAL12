class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        long long sum=0;
        unordered_map<int,int> map;
        bool check=true;
        int num=0;
        for(int i=0;i<k;i++){
            map[nums[i]]++;
            if(map[nums[i]]==2){
                check=false;
                num++;
            }
            sum+=nums[i];
        }
        if(check){
            ans=sum;
        }
        for(int i=k;i<nums.size();i++){
            sum=sum-nums[i-k];
            sum+=nums[i];
            map[nums[i-k]]--;
            if(map[nums[i-k]]==1){
                num--;
                if(num==0) check=true;
            }
            map[nums[i]]++;
            if(map[nums[i]]==2){
                check=false;
                num++;
            }
            if(check) ans=max(ans,sum);
        }
        return ans;
    }
};