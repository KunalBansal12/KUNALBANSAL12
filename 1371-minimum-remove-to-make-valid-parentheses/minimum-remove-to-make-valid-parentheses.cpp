class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open=0,close=0;
        int i=0;
        while(i<s.length()){
            if(s[i]=='(') open++;
            else if(s[i]==')') close++;
            if(close>open){
                s.erase(s.begin()+i);
                close--;
                continue;
            }
            i++;
        }
        if(open>close){
            int open1=0,close1=0;
            int i=s.length()-1;
            while(i>=0){
                if(s[i]=='(') open1++;
                else if(s[i]==')') close1++;
                if(open1>close1){
                    s.erase(s.begin()+i);
                    open1--;
                }
                i--;
            }
        }
        return s;
    }
};