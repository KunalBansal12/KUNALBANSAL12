class Solution {
public:
    #define ll long long
    int mod=1000000007;
    int lengthAfterTransformations(string s, int t) {
        vector<ll> freq(26,0);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<t;i++){
            ll j=freq[25];
            for(int i=25;i>0;i--){
                freq[i]=freq[i-1];
            }
            freq[0]=(j)%mod;
            freq[1]=(j+freq[1])%mod;
        }
        ll ans=0;
        for(int i=0;i<26;i++){
            ans=(ans+freq[i])%mod;
        }
        return ans;
    }
};