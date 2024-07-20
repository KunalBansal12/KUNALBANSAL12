class Solution {
public:
    int help(int i,int j,vector<vector<int>>& dp,string a,string b){
        if(i==a.length()) return b.length()-j;
        if(j==b.length()) return a.length()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]) return dp[i][j]=help(i+1,j+1,dp,a,b);
        return dp[i][j]=1+min({help(i+1,j,dp,a,b),help(i,j+1,dp,a,b),help(i+1,j+1,dp,a,b)});
    }

    int minDistance(string word1, string word2) {
        int n=word1.length(),m=word2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return help(0,0,dp,word1,word2);
    }
};