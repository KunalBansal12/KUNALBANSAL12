class Solution {
public:
    int getLucky(string s, int k) {
        string res="";
        for(int i=0;i<s.length();i++){
            int x=s[i]-'a'+1;
            res+=to_string(x);
        }   
        // cout<<res<<endl;   
         int sum=0;
        while(k>0){
         sum=0;
         for(int i=0;i<res.length();i++){
            sum+=(res[i]-'0');
         }
         k--;
         res=to_string(sum);
        }
        return sum;
    }
};