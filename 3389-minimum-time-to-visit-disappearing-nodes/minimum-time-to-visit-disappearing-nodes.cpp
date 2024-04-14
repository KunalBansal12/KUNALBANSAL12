class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<int> vis(n,-1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int f=edges[i][0],s=edges[i][1],c=edges[i][2];
            adj[f].push_back({s,c});
            adj[s].push_back({f,c});
        }
        pq.push({0,0});
        //{time,node}
        while(pq.size()){
            pair<int,int> temp=pq.top();
            pq.pop();
            int node=temp.second;
            int time=temp.first;
            if(vis[node]!=-1 || disappear[node]<=time){
                continue;
            }
            else{
                vis[node]=time;
                for(int i=0;i<adj[node].size();i++){
                    pair<int,int> temp=adj[node][i];
                    int cost1=temp.second;
                    int node1=temp.first;
                    if(vis[node1]==-1){
                        pq.push({time+cost1,node1});
                    }
                }
            }
        }
        return vis;
    }
};