class Solution {
public:
    int help(int ind,int n,vector<int>& vis,vector<vector<int>>& adj,int k,int parent,vector<int>& closer,vector<int>& sum){
        vis[ind]=parent;
        int close=1;
        for(int i=0;i<adj[ind].size();i++){
            if(vis[adj[ind][i]]==-1){
                int ans=help(adj[ind][i],n,vis,adj,k+1,ind,closer,sum);
                close+=ans;
                sum[0]+=ans;
            }
        }
        closer[ind]=close;
        return close;
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> vis(n,-1);
        vector<int> closer(n,0);
        vector<vector<int>> adj(n);
        vector<int> sum(n,0);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        help(0,n,vis,adj,1,0,closer,sum);

        for(int i=0;i<adj[0].size();i++){
            dfs(adj[0][i],sum,closer,adj,vis);
        }
        return sum;
    }

    void dfs(int ind,vector<int>& sum,vector<int>& closer,vector<vector<int>>& adj,vector<int>& vis){
        sum[ind]=sum[vis[ind]]-closer[ind]+(adj.size()-closer[ind]);
        for(int i=0;i<adj[ind].size();i++){
            if(sum[adj[ind][i]]==0) dfs(adj[ind][i],sum,closer,adj,vis);
        }
        return;
    }
};