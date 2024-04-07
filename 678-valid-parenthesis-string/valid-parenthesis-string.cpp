class Solution {
public:
    bool help(int ind,int sum,string s,vector<vector<int>>& dp){
        if(sum<0) return false;
        if(ind==s.length()){
            if(sum==0) return true;
            return false;
        }
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        if(sum>s.length()/2) return false;
        if(s[ind]=='(') return dp[ind][sum]=help(ind+1,sum+1,s,dp);
        else if(s[ind]==')') return dp[ind][sum]=help(ind+1,sum-1,s,dp);
        else{
            if(help(ind+1,sum,s,dp) || help(ind+1,sum+1,s,dp)) return dp[ind][sum]=1;
            if(sum>0) return dp[ind][sum]=help(ind+1,sum-1,s,dp);
        }
        return false;
    }

    bool checkValidString(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return help(0,0,s,dp);
    }
};