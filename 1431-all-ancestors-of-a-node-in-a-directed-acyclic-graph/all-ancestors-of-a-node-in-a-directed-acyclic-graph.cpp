class Solution {
public:
    void help(int x,int curr,vector<vector<int>>& adj,vector<vector<int>>& ans){
        for(int j=0;j<adj[curr].size();j++){
            if(ans[adj[curr][j]].size()==0 || ans[adj[curr][j]].back()!=x){
                ans[adj[curr][j]].push_back(x);
                help(x,adj[curr][j],adj,ans);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            help(i,i,adj,ans);
        }
        return ans;
    }
};