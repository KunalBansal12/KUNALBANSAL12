class Solution {
public:
    #define ll long long
    long long minEnd(int n, int x) {
        long long ans=0;
        vector<int> bits(64,0);
        for(int i=0;i<32;i++){
            bits[64-i-1]=x%2;
            x=x/2;
        }
        n--;
        int i=63;
        while(n!=0){
            while(i>=0 && bits[i]!=0) i--;
            if(n%2!=0) bits[i]=1;
            i--;
            n=n/2;
        }
        for(int i=0;i<64;i++){
            if(bits[i]){
                ans=ans | ((1ll)<<(64-i-1));
            }
        }
        return ans;
    }
};