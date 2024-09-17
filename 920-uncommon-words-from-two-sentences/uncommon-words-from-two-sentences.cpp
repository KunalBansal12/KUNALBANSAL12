class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> map;
        for(int i=0;i<s1.length();i++){
            if(s1[i]==' ') continue;
            string s="";
            while(i<s1.length() && s1[i]!=' '){
                s+=s1[i];
                i++;
            }
            map[s]++;
        }
        for(int i=0;i<s2.length();i++){
            if(s2[i]==' ') continue;
            string s="";
            while(i<s2.length() && s2[i]!=' '){
                s+=s2[i];
                i++;
            }
            map[s]++;
        }
        vector<string> ans;
        for(auto it:map){
            if(it.second==1) ans.push_back(it.first);
        }
        return ans;
    }
};