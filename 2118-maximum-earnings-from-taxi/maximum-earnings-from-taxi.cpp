class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        sort(rides.begin(),rides.end());
        for(int i=0;i<rides.size();i++){
            rides[i][2]+=rides[i][1]-rides[i][0];
        }
        vector<long long> dp(n+1,-1);
        int j=0;
        long long ans=0;
        for(int i=0;i<=n;i++){
            dp[i]=max(ans,dp[i]);
            ans=max(ans,dp[i]);
            while(j<rides.size() && rides[j][0]==i){
                dp[rides[j][1]]=max(dp[rides[j][1]],ans+rides[j][2]);
                j++;
            }
        }
        return dp[n];
    }
};