class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }
        int ans=1;
        for(int i=0;i<nums.size();i++){
            if(map[nums[i]]){
                map[nums[i]]--;
                int prev=nums[i]-1,next=nums[i]+1;
                while(map[prev]>0){
                    map[prev]--;
                    prev--;
                }
                while(map[next]>0){
                    map[next]--;
                    next++;
                }
                ans=max(ans,next-prev-1);
            }
        }
        return ans;
    }
};