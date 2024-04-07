class Solution {
public:
    int findpar(int j,vector<int>& par){
        if(j==par[j]) return j;
        return par[j]=findpar(par[j],par);
    }

    void union1(vector<int>& rank,vector<int>& par,int i,int j,int wt,vector<int>& w){
        i=findpar(i,par);
        j=findpar(j,par);
        if(rank[i]>rank[j]){
            par[j]=i;
            w[i]=w[i] & w[j] & wt;
        }
        else if(rank[i]<rank[j]){
            par[i]=j;
            w[j]=w[j] & w[i] & wt;
        }
        else{
            par[j]=i;
            rank[i]++;
            w[i]=w[i] & w[j] & wt;
        }
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {
        vector<int> rank(n,0);
        vector<int> par(n,0);
        vector<int> wt(n,INT_MAX);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        for(int i=0;i<edges.size();i++){
            union1(rank,par,edges[i][0],edges[i][1],edges[i][2],wt);
        }
        vector<int> ans(q.size(),0);
        for(int i=0;i<q.size();i++){
            if(q[i][0]==q[i][1]) ans[i]=0;
            else if(findpar(q[i][0],par)!=findpar(q[i][1],par)) ans[i]=-1;
            else{
                ans[i]=wt[findpar(q[i][0],par)];
            }
        }
        return ans;
    }
};