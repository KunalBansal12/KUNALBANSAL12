class Solution {
public:
#define ll long long
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        vector<ll> prefixSum(n+1,0);
        for(int i=0;i<n;i++){
            prefixSum[i+1]=prefixSum[i]+nums[i];
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            if(nums[i-1]>=k) continue;
            int low=i,high=n,mid=i;
            while(low<=high){
                if(low==high) break;
                else if(low==high-1){
                    // if(i==1) cout<<(prefixSum[high]-prefixSum[i-1])*(high-i+1)<<endl;
                    if(((prefixSum[high]-prefixSum[i-1])*(high-i+1))<k) mid=high;
                    else if((prefixSum[low]-prefixSum[i-1])*(low-i+1)<k){
                        // if(i==1) cout<<(prefixSum[low]-prefixSum[i-1])*(low-i+1)<<endl;
                        mid=low;
                    }
                    else mid=low-1;
                    cout<<mid<<endl;
                    break;
                }
                mid=low+(high-low)/2;
                // if(i==1) cout<<i<<" "<<mid<<endl;
                ll a=(prefixSum[mid]-prefixSum[i-1])*(mid-i+1);
                if(a<k) low=mid;
                else if(a>=k) high=mid;
            }
            if(mid>=i) ans+=mid-i+1;
            // cout<<mid-i+1<<endl;
        }
        return ans;
    }
};