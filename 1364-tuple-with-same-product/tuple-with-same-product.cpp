class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                int num=nums[i]*nums[j];
                ans+=map[num];
                map[num]++;
            }
        }
        return ans*8;
    }
};