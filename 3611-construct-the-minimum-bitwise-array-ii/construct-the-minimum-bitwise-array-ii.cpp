class Solution {
public:
    int help(int n){
        int ans=0,i=0,zero=0;
        while(n){
            int k=n%2;
            n/=2;
            if(k==1){
                ans+=pow(2,i);
            }
            else if(k==0 && zero==0){
                zero=1;
                ans-=pow(2,i-1);
            }
            i++;
        }
        if(zero==0) ans-=pow(2,i-1);
        return ans;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]==2) ans[i]=-1;
            else ans[i]=help(nums[i]);
        }
        return ans;
    }
};