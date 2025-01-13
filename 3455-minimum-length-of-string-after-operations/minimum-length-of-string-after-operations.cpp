class Solution {
public:
    int minimumLength(string s) {
        vector<int> count(26,0);
        for(int i=0;i<s.length();i++){
            count[s[i]-'a']++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            if(count[i]==0) continue;
            else if(count[i]%2) ans+=1;
            else ans+=2;
        }
        return ans;
    }
};