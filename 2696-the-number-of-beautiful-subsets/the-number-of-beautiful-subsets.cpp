class Solution {
public:
    int help(vector<int>& nums,int k,int i,int siz,unordered_map<int,int>& map){
        if(i==nums.size() && siz==0) return 0;
        else if(i==nums.size()) return 1;
        int a=0,b=0;
        a=help(nums,k,i+1,siz,map);
        if(!map[nums[i]-k] && !map[nums[i]+k]){
            map[nums[i]]++;
            b=help(nums,k,i+1,siz+1,map);
            map[nums[i]]--;
        }
        return a+b;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        return help(nums,k,0,0,map);
    }
};