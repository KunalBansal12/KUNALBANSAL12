class Solution {
public:
    int help(int ind,vector<vector<int>>& books,int width,vector<int>& dp){
        if(ind>=books.size()) return 0;
        if(dp[ind]!=INT_MAX) return dp[ind];
        int n=books.size();
        int w=width,ht=0;
        for(int i=ind;i<n;i++){
            if(w<books[i][0]) break;
            else{
                w=w-books[i][0];
                ht=max(ht,books[i][1]);
                dp[ind]=min(dp[ind],help(i+1,books,width,dp)+ht);
            }
        }
        return dp[ind];
    }

    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<int> dp(n,INT_MAX);
        return help(0,books,shelfWidth,dp);
    }
};