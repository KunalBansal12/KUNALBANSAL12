class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=mean*(n+rolls.size());
        int sumrolls=0;
        for(int i=0;i<rolls.size();i++){
            sumrolls+=rolls[i];
        }
        int sumreq=sum-sumrolls;
        vector<int> ans;
        if(sumreq>6*n || sumrolls>=sum || sumreq<n) return ans;
        for(int i=0;i<n;i++){
            if(sumreq-6>=n-i-1) ans.push_back(6);
            else ans.push_back(sumreq-n+i+1);
            sumreq-=ans[i];
        }
        return ans;
    }
};