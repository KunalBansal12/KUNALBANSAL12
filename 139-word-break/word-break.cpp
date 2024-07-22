class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> map;
        for(int i=0;i<wordDict.size();i++){
            map[wordDict[i]]++;
        }
        int n=s.length();
        vector<int> dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            string a="";
            for(int j=i;j<n;j++){
                a+=s[j];
                if(map[a] && dp[j+1]){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[0];
    }
};