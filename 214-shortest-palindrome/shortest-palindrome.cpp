class Solution {
public:
    string shortestPalindrome(string s) {
        string rev=s;
        reverse(rev.begin(),rev.end());
        string newst=s+'#'+rev;
        int n=newst.length();
        vector<int>kmp(n,0);
        int i=1,k=0;
        while(i<n){
            if(newst[i]==newst[k]){
                k++;
                kmp[i]=k;
                i++;
            }
            else{
                if(k>0){
                  k=kmp[k-1];  
                }
                else{
                    kmp[i]=0;
                    i++;
                }
            }
        }
        int sameprefixsufffix=kmp[n-1];
        int size=s.length();
        string toadd=rev.substr(0,size-sameprefixsufffix);
        return toadd+s;
    }
};