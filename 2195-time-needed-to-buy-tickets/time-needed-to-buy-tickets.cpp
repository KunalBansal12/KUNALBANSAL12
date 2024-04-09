class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int ans=0;
        int minE=tickets[k]-1;
        for(int i=k+1;i<tickets.size();i++){
            ans+=min(tickets[i],minE);
        }
        for(int i=0;i<=k;i++){
            ans+=min(tickets[i],minE+1);
        }
        return ans;
    }
};