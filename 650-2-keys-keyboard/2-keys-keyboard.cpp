class Solution {
public:
    int helper(int n,int x,int y){
        if(x>n){
            return 100000;
        }
        if(x==n){
            return 0;
        }
        int l=100000;
        int m=100000;
        if(x!=y){
            l=1+helper(n,x,x);
        }
        m=1+helper(n,x+y,y);
        return min(l,m);
    }

    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        return 1+helper(n,1,1);
    }
};