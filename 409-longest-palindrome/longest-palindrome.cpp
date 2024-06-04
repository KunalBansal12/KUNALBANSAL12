class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        int odd=0,ans=0;
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
            if(map[s[i]]%2==1) odd++;
            else{
                odd--;
                ans+=2;
            }
        }
        if(odd) return ans+1;
        return ans;
    }
};