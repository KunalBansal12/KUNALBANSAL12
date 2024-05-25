class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=INT_MAX,ans=0;
        for(int i=0;i<prices.size();i++){
            l=min(l,prices[i]);
            ans=max(ans,prices[i]-l);
        }
        return ans;
    }
};