class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        long long ans=0;
        for(int i=0;i<s.length();i++){
            int a=s[i]-'a';
            int b=t[i]-'a';
            long long num1=0,num2=0;
            for(int j=a;j!=b;j=(j+1)%26){
                num1+=nextCost[j];
            }
            for(int j=a;j!=b;j--){
                if(j==-1){
                    j=26;
                    continue;
                }
                num2+=previousCost[j];
            }
            ans+=min(num1,num2);
        }
        return ans;
    }
};