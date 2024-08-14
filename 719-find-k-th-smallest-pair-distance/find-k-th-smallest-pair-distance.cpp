class Solution {
public:
    int count(int el,vector<int>&nums){
        int i=0,j=1;
        int c=0;
        int n=nums.size();
        while(j<n){
            if(nums[j]-nums[i]<=el){
                c+=(j-i);
                j++;
            }
            else{
                i++;
            }  
        }
        return c;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int si=0,ei=nums[n-1]-nums[0];
        int ans=INT_MAX;
        while(si<=ei){
            int mid=(si+ei)/2;
            int c=count(mid,nums);
            if(c>=k){
                ans=min(ans,mid);
                ei=mid-1;
            }
            else si=mid+1;
        }
        return ans;
    }
};