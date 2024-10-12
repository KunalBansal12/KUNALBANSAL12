class Solution {
public:
    vector<int> vis;
    vector<vector<int>> dp;
    int f(string& source, string& pattern, int i, int j) {
        if(j == pattern.length()) return 0;
        if(i == source.length()) return INT_MAX;

        if(dp[i][j] != -1) return dp[i][j];
        int nottake=f(source,pattern,i+1,j);
        if(source[i]==pattern[j]){
            int take=f(source,pattern,i+1,j+1);
            if(take!=INT_MAX) nottake=min(nottake,take+vis[i]);
        }
        return dp[i][j]=nottake;
    }
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        int n = source.size();
        vis.resize(n, 0);
        dp.resize(n, vector<int>(pattern.length(), -1));

        for(auto it: targetIndices) vis[it] = 1;
        int ans = f(source, pattern, 0, 0);
        return targetIndices.size()-ans;
    }
};