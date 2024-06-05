class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        unordered_map<char,int> map;
        vector<string> ans;
        for(int i=0;i<words[0].length();i++){
            map[words[0][i]]++;
        }
        for(int i=1;i<words.size();i++){
            unordered_map<char,int> map1;
            for(int j=0;j<words[i].length();j++){
                if(map[words[i][j]]>map1[words[i][j]]){
                    map1[words[i][j]]++;
                }
            }
            map=map1;
        }
        for(auto it:map){
            int n=it.second;
            for(int i=0;i<n;i++){
                string s="";
                s+=it.first;
                ans.push_back(s);
            }
        }
        return ans;
    }
};