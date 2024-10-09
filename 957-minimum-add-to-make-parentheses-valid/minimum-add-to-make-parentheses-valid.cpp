class Solution {
public:
    int minAddToMakeValid(string s) {
        int num=0,ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') num++;
            else if(s[i]==')'){
                if(num==0) ans++;
                else num--;
            }
        }
        ans+=num;
        return ans;
    }
};