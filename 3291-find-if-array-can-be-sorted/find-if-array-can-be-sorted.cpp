class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        // vector<int> nums1=nums;
        vector<int> bit(n,0);
        // sort(nums1.begin(),nums1.end());
        for(int i=0;i<n;i++){
            int k=nums[i];
            while(k!=0){
                bit[i]+=(k%2);
                k=k/2;
            }
        }
        for(int i=0;i<n;i++){
            int j=i+1;
            while(j<n){
                if(bit[i]==bit[j]) j++;
                else break;
            }
            sort(nums.begin()+i,nums.begin()+j);
            i=j-1;
        }
        for(int i=0;i<n-1;i++){
            // cout<<nums[i]<<" ";
            if(nums[i+1]<nums[i]) return false;
        }
        return true;
    }
};