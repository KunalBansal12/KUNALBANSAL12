class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> map,map1;
        for(int i=0;i<s.length();i++){
            if(map.find(s[i])!=map.end()){
                if(map[s[i]]!=t[i]) return false;
            }
            else{
                if(map1.find(t[i])!=map.end()) return false;
                map[s[i]]=t[i];
                map1[t[i]]=s[i];
            }
        }
        return true;
    }
};