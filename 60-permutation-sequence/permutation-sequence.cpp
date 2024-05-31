class Solution {
public:
    int fact(int m){
        if(m==0 || m==1) return 1;
        else return m*fact(m-1);
    }

    string getPermutation(int n, int k) {
        if(n==1){
            string ans="1";
            return ans;
        }
        string s="123456789";
        string ans(n,'\0');
        int l=n;
        int ans1=0;
        for(int i=0;i<l;i++){
            int total=fact(n-1);
            int si=((k-1)/total);
            ans[i]=s[si];
            s.erase(si,1);
            if(k>total && k%total!=0) k=k%total;
            if(k%total==0) k=total;
            n=n-1;
        }
        return ans;
    }
};