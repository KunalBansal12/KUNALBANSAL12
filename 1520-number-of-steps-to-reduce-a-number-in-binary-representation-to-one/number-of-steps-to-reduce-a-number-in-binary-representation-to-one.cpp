class Solution {
public:
    int numSteps(string s) {
        int i=s.length()-1,ans=0;
        while(i>0){
            if(s[i]=='0'){
                i--;
                ans++;
            }
            else{
                int j=i;
                while(j>=0 && s[j]!='0'){
                    s[j]='0';
                    j--;
                }
                if(j>=0){
                    s[j]='1';
                    i--;
                    ans+=2;
                }
                else if(j<0){
                    s[0]='1';
                    ans+=2;
                }
            }
        }
        return ans;
    }
};