class Solution {
public:
    int tribonacci(int n) {
        if(n==0 || n==1){
            return n;
        }
        if(n==2){
            return n-1;
        }
       int *out=new int[n+1];
       out[0]=0;
       out[1]=1;
       out[2]=1;
       for(int i=3;i<=n;i++){
           out[i]=out[i-1]+out[i-2]+out[i-3];
        }
        return out[n];
    }
};