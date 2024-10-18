class Solution {
public:
    string longestPalindrome(string s) {
        int ans=0,n=s.length();
        string ans1;
        for(int k=0;k<n;k++){
            string a="";
            a+=s[k];
            int i=k-1,j=k+1,len=1;
            while(i>=0 && k<n && s[i]==s[j]){
                a=s[i]+a;
                a=a+s[j];
                i--;
                j++;
                len+=2;
            }
            if(ans<len){
                ans=len;
                ans1=a;
            }
            if(k>0 && s[k-1]==s[k]){
                len=2;
                i=k-2;
                j=k+1;
                a="";
                a=a+s[k-1];
                a=a+s[k];
                while(i>=0 && j<n && s[i]==s[j]){
                    a=s[i]+a;
                    a=a+s[j];
                    i--;
                    j++;
                    len+=2;
                }
                if(ans<len){
                    ans=len;
                    ans1=a;
                }
            }
            if(k<n-1 && s[k+1]==s[k]){
                len=2;
                i=k-1;
                j=k+2;
                a="";
                a=a+s[k];
                a=a+s[k+1];
                while(i>=0 && j<n && s[i]==s[j]){
                    a=s[i]+a;
                    a=a+s[j];
                    i--;
                    j++;
                    len+=2;
                }
                if(ans<len){
                    ans=len;
                    ans1=a;
                }
            }
        }
        return ans1;
    }
};