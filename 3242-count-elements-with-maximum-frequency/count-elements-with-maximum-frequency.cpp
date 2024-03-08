class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> map;
        int num=0;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
            num=max(num,map[nums[i]]);
        }
        int ans=0;
        for(auto it:map){
            if(it.second==num) ans+=num;
        }
        return ans;
    }
};