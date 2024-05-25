class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int a=0,b=n-1;
        for(int i=0;i<nums.size();i++){
            while(nums[i]!=1 && i>=a && i<=b){
                if(nums[i]==0){
                    swap(nums[i],nums[a]);
                    a++;
                }
                if(nums[i]==2){
                    swap(nums[i],nums[b]);
                    b--;
                }
            }
        }
        return;
    }
};