class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j});
                if(grid[i][j]==1) fresh++;
            }
        }

        int ans=0;
        while(!q.empty()){
            int ans1=ans;
            int n1=q.size();
            for(int k=0;k<n1;k++){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                cout<<i<<" "<<j<<endl;
                if(i!=0 && grid[i-1][j]==1){
                    grid[i-1][j]=2;
                    fresh--;
                    q.push({i-1,j});
                    if(ans1==ans) ans++;
                }
                if(i!=n-1 && grid[i+1][j]==1){
                    grid[i+1][j]=2;
                    fresh--;
                    q.push({i+1,j});
                    if(ans1==ans) ans++;
                }
                if(j!=0 && grid[i][j-1]==1){
                    grid[i][j-1]=2;
                    fresh--;
                    q.push({i,j-1});
                    if(ans1==ans) ans++;
                }
                if(j!=m-1 && grid[i][j+1]==1){
                    grid[i][j+1]=2;
                    fresh--;
                    q.push({i,j+1});
                    if(ans1==ans) ans++;
                }
            }
        }
        cout<<fresh<<endl;
        if(fresh==0) return ans;
        return -1;
    }
};