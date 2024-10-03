class Solution {
public:
    int bs(vector<int>& nums,int k){
        // cout<<k<<endl;
        int high=0,low=nums.size()-1,ans=-1;
        while(high<=low){
            int mid=high+(low-high)/2;
            if(nums[mid]>k){
                ans=nums[mid];
                high=mid+1;
            }
            else low=mid-1;
        }
        // cout<<ans<<endl;
        return ans;
    }

    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,vector<int>> map;
        long long sum=0;
        int ans=INT_MAX;
        map[0].push_back(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            if(sum%p==0) ans=i;
            map[sum%p].push_back(i);
        }
        if(sum%p==0) return 0;
        sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int k=(p-sum%p)%p;
            if(map[k].size()==0) continue;
            int j=bs(map[k],i);
            if(j==-1) continue;
            ans=min(ans,j-i-1);
        }
        if(ans==INT_MAX) ans=-1;
        return ans;
    }
};