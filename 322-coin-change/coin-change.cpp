class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX-1);
        dp[0]=0;
        sort(coins.begin(),coins.end());
        for(long int i=0;i<amount;i++){
            if(dp[i]==INT_MAX-1) continue;
            for(int j=0;j<coins.size();j++){
                if(i+coins[j]>amount) break;
                int k=i+coins[j];
                dp[k]=min(dp[k],dp[i]+1);
            }
        }
        if(dp[amount]==INT_MAX-1) return -1;
        return dp[amount];
    }
};