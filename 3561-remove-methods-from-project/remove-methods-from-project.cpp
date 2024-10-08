class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(int i=0;i<invocations.size();i++){
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        vector<int> vis(n,0);
        vis[k]=1;
        queue<int> q;
        q.push(k);
        while(q.size()){
            int n=q.front();
            q.pop();
            for(int i=0;i<adj[n].size();i++){
                if(!vis[adj[n][i]]){
                    vis[adj[n][i]]=1;
                    q.push(adj[n][i]);
                }
            }
        }
        bool ans=true;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                for(int j=0;j<adj[i].size();j++){
                    if(vis[adj[i][j]]){
                        ans=false;
                        break;
                    }
                }
                if(ans==false) break;
            }
        }
        vector<int> an;
        if(ans==false){
            for(int i=0;i<n;i++){
                an.push_back(i);
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(!vis[i]) an.push_back(i);
            }
        }
        return an;
    }
};