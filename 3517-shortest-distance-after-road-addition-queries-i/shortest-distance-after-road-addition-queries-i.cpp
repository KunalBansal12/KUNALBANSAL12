class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        vector<int> ans1;
        for(int i=0;i<queries.size();i++){
            vector<int> vis(n,0);
            int ans=INT_MAX;
            adj[queries[i][0]].push_back(queries[i][1]);
            queue<pair<int,int>> q;
            q.push({0,0});
            vis[0]=1;
            while(q.size()){
                int n1=q.front().first;
                int n2=q.front().second;
                q.pop();
                if(n1==n-1){
                    ans=min(ans,n2);
                    break;
                }
                for(int i=0;i<adj[n1].size();i++){
                    if(!vis[adj[n1][i]]){
                        q.push({adj[n1][i],n2+1});
                        vis[adj[n1][i]]=1;
                    }
                }
            }
            ans1.push_back(ans);
        }
        return ans1;
    }
};