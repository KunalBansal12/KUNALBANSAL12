class Solution {
public:
    string breakPalindrome(string s) {
        if(s.length()==1) return "";
        for(int i=0;i<=s.length()/2;i++){
            if(s.length()%2!=0 && i==s.length()/2){
                s[s.length()-1]='b';
                return s;
            }
            else if(s[i]!='a'){
                s[i]='a';
                return s;
            }
            if(i==s.length()-1) s[i]='b';
        }
        return s;
    }
};