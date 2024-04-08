class Solution {
public:
    int dfs(int ind,int n,unordered_map<int,bool>& vis,unordered_map<int,vector<int>>& adj){
        int ans=0;
        vis[ind]=1;
        for(int i=0;i<adj[ind].size();i++){
            if(adj[ind][i]>0 && !vis[abs(adj[ind][i])]) ans+=dfs(abs(adj[ind][i]),n,vis,adj);
            else if(adj[ind][i]<0 && !vis[abs(adj[ind][i])]) ans+=1+dfs(abs(adj[ind][i]),n,vis,adj);
        }
        return ans;
    }

    int minReorder(int n, vector<vector<int>>& c) {
        unordered_map<int,bool> vis;
        unordered_map<int,vector<int>> map;
        for(int i=0;i<n-1;i++){
            map[c[i][1]].push_back(c[i][0]);
            map[c[i][0]].push_back(-c[i][1]);
        }
        return dfs(0,n,vis,map);
    }
};