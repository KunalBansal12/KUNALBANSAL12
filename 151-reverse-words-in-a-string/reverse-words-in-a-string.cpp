class Solution {
public:
    string reverseWords(string s) {
        int i=s.length()-1,j=s.length()-1,l=j;
        string ans="";
        bool k=false;
        while(i>=0){
            if(!k && s[i]!=' '){
                l=i;
                k=true;
                i--;
            }
            else if(s[i]!=' '){
                i--;
            }
            else if(k && s[i]==' '){
                k=false;
                j=i+1;
                if(ans.length()) ans+=' ';
                while(j<=l){
                    ans=ans+s[j];
                    j++;
                }
                i--;
            }
            else if(!k && s[i]==' '){
                i--;
            }
        }
        if(s[0]!=' '){
            j=0;
            if(ans.length()) ans+=' ';
            while(j<=l){
                ans+=s[j];
                j++;
            }
        }
        return ans;
    }
};