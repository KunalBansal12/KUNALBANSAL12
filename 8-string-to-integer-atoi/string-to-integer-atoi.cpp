class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0) return 0;
        int ans=0;
        long int num=0;
        int appear=0;
        int sign=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ' && appear==0) continue;
            else if(s[i]==' ' && appear==1){
                if(sign==1) return -num;
                return num;
            }
            else if(s[i]=='.' && appear==0) return 0;
            else if(s[i]=='-'){
                if(sign!=-1 || appear==1){
                    if(sign==1) return -num;
                    return num;
                }
                sign=1;
                appear=1;
            }
            else if(s[i]=='+'){
                if(sign!=-1 || appear==1){
                    if(sign==1) return -num;
                    return num;
                }
                sign=0;
                appear=1;
            }
            else if(s[i]-'0'<=9 && s[i]-'0'>=0){
                if(-(num*10+(s[i]-'0'))<=INT_MIN && sign==1) return INT_MIN;
                if(num*10+(s[i]-'0')>=INT_MAX && sign!=1) return INT_MAX;
                num=num*10+(s[i]-'0');
                appear=1;
            }
            else if(appear==0) return 0;
            else if(appear==1) break;
        }
        if(sign==1) return -num;
        return num;
    }
};