class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        if(n==0) return m;
        else if(m==0) return n;
        vector<int> fir(m+1,0);
        vector<int> sec(m+1,0);
        for(int i=0;i<m+1;i++){
            sec[i]=m-i;
        }
        fir[m]=1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(word1[i]==word2[j]) fir[j]=sec[j+1];
                else{
                    fir[j]=1+min({sec[j],sec[j+1],fir[j+1]});
                }
            }
            sec=fir;
            fir[m]=n-i+1;
        }
        return fir[0];
    }
};


// Memoization
// class Solution {
// public:
//     int help(int i,int j,vector<vector<int>>& dp,string a,string b){
//         if(i==a.length()) return b.length()-j;
//         if(j==b.length()) return a.length()-i;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(a[i]==b[j]) return dp[i][j]=help(i+1,j+1,dp,a,b);
//         return dp[i][j]=1+min({help(i+1,j,dp,a,b),help(i,j+1,dp,a,b),help(i+1,j+1,dp,a,b)});
//     }

//     int minDistance(string word1, string word2) {
//         int n=word1.length(),m=word2.length();
//         vector<vector<int>> dp(n,vector<int>(m,-1));
//         return help(0,0,dp,word1,word2);
//     }
// };