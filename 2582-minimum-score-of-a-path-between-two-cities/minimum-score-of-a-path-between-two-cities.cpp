class Solution {
public:
    void dfs(int end,int start,vector<vector<pair<int,int>>>& adj,vector<int>& vis,int& edge){
        vis[start]=1;
        for(int i=0;i<adj[start].size();i++){
            edge=min(edge,adj[start][i].second);
            if(!vis[adj[start][i].first]){
                dfs(end,adj[start][i].first,adj,vis,edge);
            }
        }
        // vis[start]=0;
        // if(ans!=INT_MAX) return ans;
        return;
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]-1].push_back({roads[i][1]-1,roads[i][2]});
            adj[roads[i][1]-1].push_back({roads[i][0]-1,roads[i][2]});
        }
        vector<int> vis(n,0);
        int a=INT_MAX;
        dfs(n-1,0,adj,vis,a);
        return a;
    }
};