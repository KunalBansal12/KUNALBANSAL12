class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int sum=0,ans=0,in=0;
        for(int i=0;i<s.length();i++){
            sum+=abs(s[i]-t[i]);
            if(sum>maxCost){
                while(in<=i && sum>maxCost){
                    sum-=abs(s[in]-t[in]);
                    in++;
                }
            }
            if(sum<=maxCost) ans=max(ans,i-in+1);
        }
        return ans;
    }
};