class Solution {
public:
    void backtrack(int ind,string& pattern,string& ans,string num,vector<int>& used){
        if(ind==pattern.length()+1){
            ans=min(ans,num);
            return;
        }
        if(ind==0){
            for(int i=0;i<9;i++){
                num[ind]=('1'+i);
                used[i]=1;
                backtrack(ind+1,pattern,ans,num,used);
                used[i]=0;
            }
        }
        else{
            if(pattern[ind-1]=='I'){
                for(int i=(num[ind-1]-'1')+1;i<9;i++){
                    if(!used[i]){
                        num[ind]=('1'+i);
                        used[i]=1;
                        backtrack(ind+1,pattern,ans,num,used);
                        used[i]=0;
                    }
                }
            }
            else if(pattern[ind-1]=='D'){
                for(int i=(num[ind-1]-'1')-1;i>=0;i--){
                    if(!used[i]){
                        num[ind]=('1'+i);
                        used[i]=1;
                        backtrack(ind+1,pattern,ans,num,used);
                        used[i]=0;
                    }
                }
            }
        }
        return;
    }

    string smallestNumber(string pattern) {
        string ans="",num="";
        for(int i=0;i<=pattern.length();i++){
            ans+="9";
            num+=" ";
        }
        vector<int> used(9,0);
        backtrack(0,pattern,ans,num,used);
        return ans;
    }
};