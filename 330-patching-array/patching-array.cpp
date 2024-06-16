#define ll long long
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        ll miss=1;
        int result=0,i=0;
        while(miss<=n){
            if(i<nums.size() && nums[i]<=miss){
                miss+=nums[i];
                i++;
            }
            else{
                miss+=miss;
                result++;
            }
        }
        return result;
    }
};