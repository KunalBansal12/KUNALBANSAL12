class Solution {
public:
#define ll long long
    int mod=1000000007;
    // int help(int ind,string s,vector<ll>& dp){
    //     // cout<<ind<<" "<<count<<endl;
    //     if(ind>=s.length()-1) return 1;
    //     // else if(ind>=s.length()) return 0;
    //     if(dp[ind]!=-1) return dp[ind];
    //     ll ans=0;
    //     if(s[ind]==s[ind+1]){
    //         ans+=help(ind+2,s,dp);
    //         if(ind+2<s.length() && s[ind]==s[ind+2]){
    //             ans+=help(ind+3,s,dp);
    //             if(s[ind]=='7' || s[ind]=='9'){
    //                 if(ind+3<s.length() && s[ind]==s[ind+3]) ans+=help(ind+4,s,dp);
    //             }
    //         }
    //     }
    //     ans+=help(ind+1,s,dp);
    //     return dp[ind]=ans%mod;
    // }

    int countTexts(string s) {
        int n=s.length();
        vector<ll> dp(n+4,0);
        dp[n-1]=1;
        dp[n]=1;
        dp[n+1]=1;
        dp[n+2]=1;
        // dp[n+3]=1;
        for(int i=n-2;i>=0;i--){
            ll ans=0;
            ans+=dp[i+1];
            if(s[i]==s[i+1]){
               ans+=dp[i+2];
               if(i+2<s.length() && s[i]==s[i+2]){
                   ans+=dp[i+3];
                   if(s[i]=='7' || s[i]=='9'){
                       if(i+3<s.length() && s[i]==s[i+3]) ans+=dp[i+4];
                   }
               }
            }
            dp[i]=ans%mod;
        }
        return dp[0];
    }
};