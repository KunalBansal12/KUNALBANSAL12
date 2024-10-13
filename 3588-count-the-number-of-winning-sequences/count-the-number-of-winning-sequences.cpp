class Solution {
public:
    #define ll long long
    int mod=1000000007;
        unordered_map<char,int> map;
    int help(int i,int j,int k,vector<vector<vector<int>>>& dp,string& s,vector<vector<int>>& win){
        // cout<<i<<" "<<j<<" "<<k<<endl;
        if(i==s.length()){
            if(j>0) return 1;
            else return 0;
        }
        int n=s.length();
        if(dp[i][n+j][k]!=-1) return dp[i][n+j][k];
        int a=help(i+1,j+win[map[s[i]]][0],0,dp,s,win);
        int b=help(i+1,j+win[map[s[i]]][1],1,dp,s,win);
        int c=help(i+1,j+win[map[s[i]]][2],2,dp,s,win);
        if(k==0) a=0;
        else if(k==1) b=0;
        else c=0;
        return dp[i][n+j][k]=((a+b)%mod+c)%mod;
    }

    int countWinningSequences(string s) {
        int n=s.length();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2*n+1,vector<int>(3,-1)));
        map['F']=0;
        map['W']=1;
        map['E']=2;
        vector<vector<int>> win={{0,1,-1},{-1,0,1},{1,-1,0}};
        ll a=help(1,win[map[s[0]]][map['F']],0,dp,s,win);
        ll b=help(1,win[map[s[0]]][map['W']],1,dp,s,win);
        ll c=help(1,win[map[s[0]]][map['E']],2,dp,s,win);
        return ((a+b)%mod+c)%mod;
    }
};