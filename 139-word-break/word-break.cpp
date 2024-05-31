class Solution {
public:
    bool helper(string s,unordered_map<string,bool>& dict,int si,vector<int>& dp){
        if(si>=s.length()) return true;
        if(dp[si]!=-1) return dp[si];
        for(int i=si;i<s.length();i++){
            if(dict[s.substr(si,i-si+1)]){
                bool ans=helper(s,dict,i+1,dp);
                dp[si]=ans;
                if(ans==true) return true;
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> dict;
        for(int i=0;i<wordDict.size();i++){
            dict[wordDict[i]]=true;
        }
        vector<int> dp(s.length(),-1);
        return helper(s,dict,0,dp);
    }
};