class Solution {
public:
    int numberOfSubstrings(string s) {
        int si=0,li=s.length(),count=0;
        unordered_map<char,int> map;
        for(int i=0;i<li;i++){
            map[s[i]]++;
            while(map['a']>=1 && map['b']>=1 && map['c']>=1){
                count+=(li-i);
                map[s[si]]--;
                si++;
            }
        }
        return count;
    }
};