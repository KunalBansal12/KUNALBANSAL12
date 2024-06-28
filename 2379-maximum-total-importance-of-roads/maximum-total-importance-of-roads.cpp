class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> edge(n,0);
        for(int i=0;i<roads.size();i++){
            edge[roads[i][0]]++;
            edge[roads[i][1]]++;
        }
        sort(edge.begin(),edge.end());
        long long ans=0;
        for(long long i=n;i>0;i--){
            ans+=edge[i-1]*i;
        }
        return ans;
    }
};