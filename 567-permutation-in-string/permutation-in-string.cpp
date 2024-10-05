class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        unordered_map<int,int> map1;
        unordered_map<int,int> map2;
        for(int i=0;i<s1.length();i++){
            map1[s1[i]-'a']++;
            map2[s2[i]-'a']++;
        }
        int count=0;
        for(int i=0;i<26;i++){
            if(map1[i]==map2[i]) count++;
        }
        int l=0,r=s1.length()-1;
        for(int i=s1.length();i<s2.length();i++){
            if(count==26) return true;
            map2[s2[i]-'a']++;
            if(map2[s2[i]-'a']==map1[s2[i]-'a']+1) count--;
            else if(map2[s2[i]-'a']==map1[s2[i]-'a']) count++;
            map2[s2[l]-'a']--;
            if(map2[s2[l]-'a']+1==map1[s2[l]-'a']) count--;
            else if(map2[s2[l]-'a']==map1[s2[l]-'a']) count++;
            l++;
        }
        if(count==26) return true;
        return false;
    }
};