#define ll long long
class Solution {
public:
    // ll power(ll m){
    //     ll ans=1;
    //     for(int i=0;i<m;i++){
    //         ans*=2;
    //     }
    //     return ans;
    // }

    char kthCharacter(long long k, vector<int>& operations) {
        int rounds=0;
        ll j=k;
        while(k!=1){
            ll m=log2(k-1);
            // cout<<m<<endl;
            ll pow2=pow(2,m);
            if(j>pow2) rounds+=operations[m];
            if(j>pow2) j=j-pow2;
            // cout<<rounds<<endl;
            k=pow2;
        }
        return ('a'+(rounds%26));
    }
};