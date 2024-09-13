class Solution {
public:
vector<vector<int>> pos={{1,0},{0,-1},{-1,0},{0,1}};
    void help(int i,int j,int& col,int& size,vector<vector<int>>& grid,vector<vector<int>>& vis){
        vis[i][j]=col;
        int n=grid.size(),m=grid[0].size();
        size++;
        for(int k=0;k<4;k++){
            int newi=i+pos[k][0];
            int newj=j+pos[k][1];
            if(newi>=0 && newj>=0 && newi<n && newj<m && grid[newi][newj]==1 && vis[newi][newj]==-1){
                help(newi,newj,col,size,grid,vis);
            }
        }
        return;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,-1));
        int col=0;
        int ans=0;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==-1 && grid[i][j]==1){
                    int size=0;
                    help(i,j,col,size,grid,vis);
                    map[col]=size;
                    ans=max(ans,size);
                    col++;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    unordered_map<int,int> island;
                    int temp=0;
                    for(int k=0;k<4;k++){
                        int newi=i+pos[k][0];
                        int newj=j+pos[k][1];
                        if(newi>=0 && newj>=0 && newi<n && newj<m && grid[newi][newj]==1){
                            if(island.find(vis[newi][newj])==island.end()){
                                temp+=map[vis[newi][newj]];
                                island[vis[newi][newj]]=1;
                            }
                        }
                    }
                    temp+=1;
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};