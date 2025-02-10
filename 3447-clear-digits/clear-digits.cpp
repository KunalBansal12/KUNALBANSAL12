class Solution {
public:
    string clearDigits(string s) {
        int n=s.size();
        int count=0;
        string ans="";
        for(int i=n-1;i>=0;i--){
            if(s[i]-'a'>=0 && s[i]-'a'<26){
                if(count==0) ans+=s[i];
                else count--;
            }
            else count++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};