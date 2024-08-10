class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n=nums.size();
        map<int,int> mp;
        mp[nums[0]]++;
        for(int j=1;j<n;j++){
            if(j-indexDiff-1>=0){
                mp[nums[j-indexDiff-1]]--;
                if(mp[nums[j-indexDiff-1]]==0) mp.erase(nums[j-indexDiff-1]);
            }
            auto it=mp.lower_bound(nums[j]);
            if(it!=mp.end() && abs(nums[j]-(it->first))<=valueDiff) return true;
            if(it!=mp.begin()){
                it--;
              if(abs(nums[j]-(it->first))<=valueDiff) return true;
            }
            mp[nums[j]]++;
        }
        return false;
    }
};