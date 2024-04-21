class Solution {
public:
int tx=INT_MAX;
int ty=INT_MAX;
int bx=INT_MIN;
int by=INT_MIN;
    void help(int i,int j,vector<vector<int>>& l,vector<vector<bool>>& vis){
        if(i<0 || j<0 || i>=l.size() || j>=l[0].size()) return;
        if(l[i][j]==0) return;
        if(vis[i][j]) return;
        tx=min(tx,i);
        ty=min(ty,j);
        bx=max(bx,i);
        by=max(by,j);
        vis[i][j]=true;
        help(i+1,j,l,vis);
        help(i,j+1,l,vis);
        help(i-1,j,l,vis);
        help(i,j-1,l,vis);
        return;
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] || !land[i][j]) continue;
                help(i,j,land,vis);
                vector<int> t;
                t.push_back(tx);
                t.push_back(ty);
                t.push_back(bx);
                t.push_back(by);
                ans.push_back(t);
                tx=INT_MAX;
                ty=INT_MAX;
                bx=INT_MIN;
                by=INT_MIN;
            }
        }
        return ans;
    }
};