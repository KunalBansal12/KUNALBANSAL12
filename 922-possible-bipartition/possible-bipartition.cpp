class Solution {
public:
    bool help(int l,int n,vector<vector<int>>& adj,vector<int>& vis){
        vis[l]=1;
        int sign=-1;
        queue<int> q;
        q.push(l);
        while(q.size()){
            int k=q.size();
            for(int i=0;i<k;i++){
                int t=q.front();
                q.pop();
                for(int j=0;j<n;j++){
                    if(adj[t][j] && vis[j]==0){
                        q.push(j);
                        vis[j]=sign;
                    }
                    else if(adj[t][j] && vis[j]==-sign) return false;
                }
            }
            sign=-sign;
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& d) {
        vector<vector<int>> adj(n,vector<int>(n,0));
        for(int i=0;i<d.size();i++){
            adj[d[i][0]-1][d[i][1]-1]=1;
            adj[d[i][1]-1][d[i][0]-1]=1;
        }
        vector<int> vis(n,0);
        bool check=true;
        for(int i=0;i<n;i++){
            if(vis[i]==0) check=help(i,n,adj,vis);
            if(check==false) return false;
        }
        return true;
    }
};