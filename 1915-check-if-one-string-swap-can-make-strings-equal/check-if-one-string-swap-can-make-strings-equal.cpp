class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int one=-1,two=-1,compa=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                compa++;
                if(compa>2) return false;
                if(one==-1) one=i;
                else if(two==-1) two=i;
            }
        }
        if(compa==1) return false;
        else if(compa==0) return true;
        if(s1[one]==s2[two] && s1[two]==s2[one]) return true;
        return false;
    }
};