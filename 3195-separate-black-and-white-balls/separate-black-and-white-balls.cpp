class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        int j=s.length()-1;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]=='1' && i==j){
                j--;
            }
            else if(s[i]=='1'){
                ans+=(j-i);
                j--;
            }
        }
        return ans;
    }
};