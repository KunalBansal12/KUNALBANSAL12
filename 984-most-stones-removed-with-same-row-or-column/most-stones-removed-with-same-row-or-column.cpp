class Solution {
public:
    void dfs(int node,vector<vector<int>>& edges,vector<int>& vis,int& ans){
        vis[node]=1;
        for(int i=0;i<edges[node].size();i++){
            if(!vis[edges[node][i]]){
                dfs(edges[node][i],edges,vis,ans);
                ans++;
            }
        }
        return;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>> edges(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0]){
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
                else if(stones[i][1]==stones[j][1]){
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(i,edges,vis,ans);
        }
        return ans;
    }
};