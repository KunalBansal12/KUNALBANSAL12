#define ll long long int
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k=primes.size();
        vector<int> ind(k,0);
        vector<int> dp(n,0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            long long mini=LLONG_MAX;
            for(int j=0;j<k;j++){
                mini=min(mini,(long long)primes[j]*dp[ind[j]]);
            }

            dp[i]=mini;
            for(int j=0;j<k;j++){
                if(mini==(long long)primes[j]*dp[ind[j]]) ind[j]++;
            }
        }
        return dp[n-1];
    }
};