class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> pref(n+1,0);
        for(int i=0;i<words.size();i++){
            pref[i+1]=pref[i];
            if(words[i][0]=='a' || words[i][0]=='e' || words[i][0]=='i' || words[i][0]=='o' || words[i][0]=='u'){
                int l=words[i].length();
                if(words[i][l-1]=='a' || words[i][l-1]=='e' || words[i][l-1]=='i' || words[i][l-1]=='o' || words[i][l-1]=='u'){
                    pref[i+1]+=1;
                }
            }
        }
        vector<int> ans(queries.size(),0);
        for(int i=0;i<queries.size();i++){
            ans[i]=pref[queries[i][1]+1]-pref[queries[i][0]];
        }
        return ans;
    }
};