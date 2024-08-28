class Solution {
public:
    int countOrders(int n) {
        n*=2;
        long long mod=1000000007;
        long long ans=1;
        while(n){
            ans*=n;
            n--;
            // if(n==0){
            //     ans/=2;
            //     return ans;
            // }
            ans*=n;
            n--;
            ans=ans/2;
            ans=ans%mod;
        }
        return ans;
    }
};