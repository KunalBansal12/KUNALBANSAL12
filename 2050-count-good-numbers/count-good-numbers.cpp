class Solution {
public:
long long int h=1000000007;
    int power(int x,long long int n){
        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        if(n%2==0){
            long long int a=power(x,n/2);
            if(a>h){
                a=a%h;
            }
            a*=a;
            if(a>h){
                a=a%h;
            }
            return a;
        }
        else{
            long long int b=power(x,n/2);
            if(b>h){
                b=b%h;
            }
            b=b*b;
            if(b>h){
                b=b%h;
            }
            b=b*x;
            if(b>h){
                b=b%h;
            }
            return b;
        }
    }

    int countGoodNumbers(long long n) {
        long long op=n/2;
        long long ep=n-op;
        int a=power(4,op);
        int b=power(5,ep);
        int ans=(int)(((long)a*b)%h);
        return ans;
    }
};