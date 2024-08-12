class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int> map;
        vector<int> index(26,0);
        for(int i=0;i<s.length();i++){
            map[s[i]]++;
        }
        string st="";
        for(int i=0;i<s.length();i++){
            if(index[s[i]-'a']){
                map[s[i]]--;
                continue;
            }
            else{
                index[s[i]-'a']=i+1;
                st+=s[i];
                map[s[i]]--;
                for(int j=st.length()-2;j>=0;j--){
                    if(index[st[j]-'a'] && map[st[j]] && st[j]>s[i]){
                        index[st[j]-'a']=0;
                    }
                    else if(index[st[j]-'a'] && !map[st[j]]) break;
                }
            }
        }
        string ans="";
        for(int i=st.length()-1;i>=0;i--){
            if(!map[st[i]]){
                ans=st[i]+ans;
                map[st[i]]++;
            }
        }
        return ans;
    }
};