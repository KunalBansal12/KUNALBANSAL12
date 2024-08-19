class Solution {
public:
    int help(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
        if(i==s1.length()){
            return s2.length()-j;
        }
        if(j==s2.length()) return s1.length()-i;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        if(s1[i]==s2[j]) ans=min(ans,1+help(i+1,j+1,s1,s2,dp));
        else{
            ans=min(ans,1+help(i+1,j,s1,s2,dp));
            ans=min(ans,1+help(i,j+1,s1,s2,dp));
        }
        return dp[i][j]=ans;
    }

    void getans(vector<vector<int>>& dp,string& s,int i,int j,string& s1,string& s2){
        if(i==s1.length()){
            for(int k=j;k<s2.length();k++){
                s+=s2[k];
            }
            return;
        }
        else if(j==s2.length()){
            for(int k=i;k<s1.length();k++){
                s+=s1[k];
            }
            return;
        }
        if(s1[i]==s2[j]){
            s+=s1[i];
            getans(dp,s,i+1,j+1,s1,s2);
        }
        else{
            if(help(i+1,j,s1,s2,dp)<=help(i,j+1,s1,s2,dp)){
                s+=s1[i];
                getans(dp,s,i+1,j,s1,s2);
            }
            else{
                s+=s2[j];
                getans(dp,s,i,j+1,s1,s2);
            }
        }
        return;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length(),m=str2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        help(0,0,str1,str2,dp);
        string s="";
        getans(dp,s,0,0,str1,str2);
        return s;
    }
};