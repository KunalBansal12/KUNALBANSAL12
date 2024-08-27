class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<double,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,double>>pq;
        pq.push({0.0,start_node});
        vector<double>distance(n,INT_MIN);
        distance[start_node]=0.0;
        while(pq.size()){
            int node=pq.top().second;
            double dist=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                if(dist==0){
                  if(distance[it.first]<it.second){
                    distance[it.first]=it.second;
                    pq.push({distance[it.first],it.first});
                    } 
                }
                else if(distance[it.first]<dist*it.second){
                    distance[it.first]=dist*it.second;
                    pq.push({distance[it.first],it.first});
                }
            }
        }
        if(distance[end_node]==INT_MIN)return 0.0;
        return distance[end_node];
    }
};