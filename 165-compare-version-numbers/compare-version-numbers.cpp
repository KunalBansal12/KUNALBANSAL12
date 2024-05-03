class Solution {
public:
    int helper(string s,int& i){
        int x=0;
        if(i==s.length()) return 0;
        while(s[i]!='.' && i<s.length()){
            x=x*10+(s[i]-'0');
            i++;
        }
        return x;
    }

    int compareVersion(string version1, string version2) {
        int n=version1.length(),m=version2.length();
        int i=0,j=0;
        while(i<n || j<m){
            int x=helper(version1,i);
            int y=helper(version2,j);
            if(x>y) return 1;
            else if(x<y) return -1;
            if(i<n) i++;
            if(j<m) j++;
        }
        return 0;
    }
};