class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int result=0;
        vector<int> resultarr(k,0);
        resultarr[0]=1;
        int sum=0;
        int remainder=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            remainder=((sum)%k+k)%k;
            result+=resultarr[remainder];
            resultarr[remainder]++;
        }
        return result;
    }
};