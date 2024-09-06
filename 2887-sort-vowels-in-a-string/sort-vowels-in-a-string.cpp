class Solution {
public:
    string sortVowels(string s) {
        unordered_map<int,int> map;
        map['a']++;
        map['e']++;
        map['i']++;
        map['o']++;
        map['u']++;
        map['A']++;
        map['E']++;
        map['I']++;
        map['O']++;
        map['U']++;
        vector<char> ans;
        for(int i=0;i<s.length();i++){
            if(map[s[i]]) ans.push_back(s[i]);
        }
        sort(ans.begin(),ans.end());
        int j=0;
        for(int i=0;i<s.length();i++){
            if(map[s[i]]){
                s[i]=ans[j];
                j++;
            }
        }
        return s;
    }
};