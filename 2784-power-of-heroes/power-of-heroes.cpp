#define ll unsigned long long int
class Solution {
    int mod=1000000007;
public:
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        ll ans=0;
        ll sum=0;
        for(int i=0;i<n;i++){
            ll pow=((ll)(nums[i])*nums[i])%mod;
            ll curr=((ll)(nums[i])*pow)%mod;
            ll nex=(sum*pow)%mod;
            ll s=(curr+nex)%mod;
            ans=(ans+s)%mod;
            sum=(sum*2)%mod;
            sum=(sum+nums[i])%mod;
        }
        return ans%mod;
    }
};