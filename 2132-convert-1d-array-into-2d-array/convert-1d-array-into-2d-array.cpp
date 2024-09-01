class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>>ans;
        int c=0;
        vector<int>t;
        for(int i=0;i<original.size();i++){
            t.push_back(original[i]);
            c++;
            if(c==n){
                ans.push_back(t);
                t.clear();
                c=0;
            }
        }
        if(t.size()!=0||ans.size()!=m||ans[0].size()!=n){
            ans.clear();
            return ans;
        }
        return ans;
    }
};