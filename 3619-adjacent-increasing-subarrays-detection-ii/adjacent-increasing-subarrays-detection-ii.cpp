class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int> len;
        int n=nums.size();
        int num=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]) num++;
            else{
                len.push_back(num);
                num=1;
            }
        }
        len.push_back(num);
        int maxi=0,ans=0;
        for(int i=0;i<len.size()-1;i++){
            ans=max(ans,min(len[i],len[i+1]));
            maxi=max(len[i],maxi);
        }
        maxi=max(len[len.size()-1],maxi);
        return max(ans,maxi/2);
    }
};