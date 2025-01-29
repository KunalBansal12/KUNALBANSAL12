class Solution {
public:
    int findpar(int j,vector<int>& par){
        if(j==par[j]) return j;
        return par[j]=findpar(par[j],par);
    }

    void union1(vector<int>& rank,vector<int>& par,int i,int j){
        i=findpar(i,par);
        j=findpar(j,par);
        if(rank[i]<rank[j]) par[i]=j;
        else if(rank[i]>rank[j]) par[j]=i;
        else{
            par[j]=i;
            rank[i]++;
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> rank(n,0);
        vector<int> par(n,-1);
        vector<int> ans(2);
        for(int i=0;i<n;i++) par[i]=i;
        for(int i=0;i<edges.size();i++){
            if(findpar(edges[i][0]-1,par)==findpar(edges[i][1]-1,par)) return edges[i];
            union1(rank,par,edges[i][0]-1,edges[i][1]-1);
        }
        return ans;
    }
};