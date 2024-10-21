class Solution {
public:
    int help(int ind,int ans,string& s,unordered_map<string,int>& map){
        if(ind==s.length()) return ans;
        string temp="";
        int num=0;
        for(int i=ind;i<s.length();i++){
            temp+=s[i];
            if(map[temp]==0){
                map[temp]=1;
                num=max(num,help(i+1,ans+1,s,map));
                map[temp]=0;
            }
        }
        return num;
    }

    int maxUniqueSplit(string s) {
        unordered_map<string,int> map;
        return help(0,0,s,map);
    }
};