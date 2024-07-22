class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        int x=cuts.size();
        vector<vector<int>> dp(x,vector<int>(x,100000000));
        for(int i=0;i<x;i++){
            for(int j=0;j<=i+1;j++){
                if(j<x) dp[i][j]=0;
            }
        }
        for(int j=2;j<x;j++){
            for(int i=0;i<x-j;i++){
                for(int k=i+1;k<j+i;k++){
                    dp[i][j+i]=min(dp[i][j+i],cuts[j+i]-cuts[i]+dp[i][k]+dp[k][j+i]);
                }
            }
        }
        return dp[0][x-1];
    }
};


// Memoization
// class Solution {
// public:
//     int helper(int n,vector<int>& cuts,vector<vector<int>>& dp,int i,int j){
//         if(i>=j) return 0;
//         if(i+1==j) return 0;
//         if(dp[i][j]!=INT_MAX) return dp[i][j];
//         for(int k=i+1;k<j;k++){
//             dp[i][j]=min(dp[i][j],cuts[j]-cuts[i]+helper(n,cuts,dp,i,k)+helper(n,cuts,dp,k,j));
//         }
//         return dp[i][j];
//     }

//     int minCost(int n, vector<int>& cuts) {
//         int x=cuts.size();
//         cuts.push_back(0);
//         sort(cuts.begin(),cuts.end());
//         cuts.push_back(n);
//         vector<vector<int>> dp(x+2,vector<int>(x+2,INT_MAX));
//         return helper(n,cuts,dp,0,x+1);
//     }
// };