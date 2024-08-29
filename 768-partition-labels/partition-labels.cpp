class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> map;
        for(int i=0;i<s.length();i++) map[s[i]]++;
        vector<int> ans;
        int sum=0,diff=0;
        unordered_map<char,int> map1;
        for(int i=0;i<s.length();i++){
            map1[s[i]]++;
            if(map1[s[i]]==1) diff++;
            if(map1[s[i]]==map[s[i]]) diff=max(0,diff-1);
            sum++;
            if(diff==0){
                ans.push_back(sum);
                sum=0;
            }
            else if(i==s.length()-1) ans.push_back(sum);
        }
        return ans;
    }
};