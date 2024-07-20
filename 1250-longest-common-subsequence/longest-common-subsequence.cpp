class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<int> fir(m+1,0);
        vector<int> sec(m+1,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(text1[i]==text2[j]) fir[j]=sec[j+1]+1;
                else fir[j]=max(fir[j+1],sec[j]);
            }
            sec=fir;
        }
        return fir[0];
    }
};


// Optimized- tabulation
// class Solution {
// public:
//     int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.size(),m=text2.size();
//         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
//         for(int i=n-1;i>=0;i--){
//             for(int j=m-1;j>=0;j--){
//                 if(text1[i]==text2[j]){
//                     dp[i][j]=1+dp[i+1][j+1];
//                 }
//                 else{
//                     dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
//                 }
//             }
//         }
//         return dp[0][0];
//     }
// };


// TLE - Memoization
// class Solution {
// public:
//     int help(int i,int j,vector<vector<int>>& dp,string text1,string text2){
//         if(i==dp.size() || j==dp[0].size()) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(text1[i]==text2[j]) return dp[i][j]=1+help(i+1,j+1,dp,text1,text2);
//         return dp[i][j]=max(help(i+1,j,dp,text1,text2),help(i,j+1,dp,text1,text2));
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.length(),m=text2.length();
//         vector<vector<int>> dp(n,vector<int>(m,-1));
//         return help(0,0,dp,text1,text2);
//     }
// };