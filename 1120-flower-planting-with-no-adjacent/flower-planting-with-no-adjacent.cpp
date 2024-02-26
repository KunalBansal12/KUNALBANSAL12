class Solution {
public:
    void dfs(int i,int c,vector<vector<int>>& adj,vector<int>& color){
        color[i]=c;
        if(c==4) c=1;
        else c++;
        for(auto v:adj[i]){
            if(color[v]==0) dfs(v,c,adj,color);
            else if(color[v]==color[i]) dfs(i,c,adj,color);
        }
        return;
    }

    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> color(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<paths.size();i++){
            adj[paths[i][0]-1].push_back(paths[i][1]-1);
            adj[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        for(int i=0;i<n;i++){
            if(color[i]==0) dfs(i,1,adj,color);
        }
        return color;
    }
};