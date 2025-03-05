class Solution {
public:
    long long coloredCells(int n) {
        if(n==1) return 1;
        // int side=0;
        long long ans=1;
        long long a=(((long long)(n-1))*n)/2;
        ans+=a*4;
        // for(int i=1;i<n;i++){
        //     ans+=side+4;
        //     side+=4;
        // }
        return ans;
    }
};