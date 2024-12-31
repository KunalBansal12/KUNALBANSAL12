class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int maxi=days[days.size()-1];
        vector<int> dp(maxi+1,0);
        for(int i=0;i<days.size();i++){
            dp[days[i]]=days[i];
        }
        for(int i=1;i<maxi+1;i++){
            if(dp[i]==0) dp[i]=dp[i-1];
            else dp[i]=min(costs[0]+dp[i-1],min(costs[1]+dp[max(0,i-7)],costs[2]+dp[max(0,i-30)]));
        }
        return dp[maxi];
    }
};