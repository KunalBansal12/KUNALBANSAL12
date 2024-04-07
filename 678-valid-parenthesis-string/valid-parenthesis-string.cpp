// class Solution {
// public:
//     bool help(int ind,int sum,string s,vector<vector<int>>& dp){
//         if(sum<0) return false;
//         if(ind==s.length()){
//             if(sum==0) return true;
//             return false;
//         }
//         if(dp[ind][sum]!=-1) return dp[ind][sum];
//         if(sum>s.length()/2) return false;
//         if(s[ind]=='(') return dp[ind][sum]=help(ind+1,sum+1,s,dp);
//         else if(s[ind]==')') return dp[ind][sum]=help(ind+1,sum-1,s,dp);
//         else{
//             if(help(ind+1,sum,s,dp) || help(ind+1,sum+1,s,dp)) return dp[ind][sum]=1;
//             if(sum>0) return dp[ind][sum]=help(ind+1,sum-1,s,dp);
//         }
//         return false;
//     }

//     bool checkValidString(string s) {
//         int n=s.length();
//         vector<vector<int>> dp(n,vector<int>(n,-1));
//         return help(0,0,s,dp);
//     }
// };

// Another solution
class Solution {
    public: bool checkValidString(string s) {
        int cmin = 0, cmax = 0; // open parentheses count in range [cmin, cmax]
        for (char c : s) {
            if (c == '(') {
                cmax++;
                cmin++;
            } else if (c == ')') {
                cmax--;
                cmin--;
            } else if (c == '*') {
                cmax++; // if `*` become `(` then openCount++
                cmin--; // if `*` become `)` then openCount--
                // if `*` become `` then nothing happens
                // So openCount will be in new range [cmin-1, cmax+1]
            }
            if (cmax < 0) return false; // Currently, don't have enough open parentheses to match close parentheses-> Invalid
                                        // For example: ())(
            cmin = max(cmin, 0);   // It's invalid if open parentheses count < 0 that's why cmin can't be negative
        }
        return cmin == 0; // Return true if can found `openCount == 0` in range [cmin, cmax]
    }
};