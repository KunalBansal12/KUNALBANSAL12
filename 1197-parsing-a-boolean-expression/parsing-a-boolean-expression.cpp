class Solution {
public:
    bool parseBoolExpr(string s) {
        stack<char> st;
        for(int i=s.length()-1;i>=0;i--){
            if(s[i]==')') st.push(s[i]);
            else if(s[i]==',') continue;
            else if(s[i]=='t' || s[i]=='f') st.push(s[i]);
            else if(s[i]=='(') continue;
            else if(s[i]=='|'){
                bool check=false;
                while(st.top()!=')'){
                    char c=st.top();
                    st.pop();
                    if(c=='t') check=check | c;
                }
                st.pop();
                if(check) st.push('t');
                else st.push('f');
            }
            else if(s[i]=='&'){
                bool check=true;
                while(st.top()!=')'){
                    char c=st.top();
                    st.pop();
                    if(c=='f') check=check & c;
                }
                st.pop();
                if(check) st.push('t');
                else st.push('f');
            }
            else if(s[i]=='!'){
                bool check;
                if(st.top()=='t') check=false;
                else check=true;
                st.pop();
                st.pop();
                if(check) st.push('t');
                else st.push('f');
            }
        }
        if(st.top()=='t') return true;
        return false;
    }
};