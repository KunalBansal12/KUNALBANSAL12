class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='0') continue;
                else if(grid[i][j]=='2') continue;
                else if(grid[i][j]=='1'){
                    grid[i][j]='2';
                    num++;
                    pair<int,int> p;
                    p.first=i;
                    p.second=j;
                    q.push(p);
                    while(q.size()){
                        pair<int,int> f=q.front();
                        q.pop();
                        if(f.first-1>=0){
                            if(grid[f.first-1][f.second]=='1'){
                                grid[f.first-1][f.second]='2';
                                pair<int,int> l;
                                l.first=f.first-1;
                                l.second=f.second;
                                q.push(l);
                            }
                        }
                        if(f.second-1>=0){
                            if(grid[f.first][f.second-1]=='1'){
                                grid[f.first][f.second-1]='2';
                                pair<int,int> l;
                                l.first=f.first;
                                l.second=f.second-1;
                                q.push(l);
                            }
                        }
                        if(f.second+1<m){
                            if(grid[f.first][f.second+1]=='1'){
                                grid[f.first][f.second+1]='2';
                                pair<int,int> l;
                                l.first=f.first;
                                l.second=f.second+1;
                                q.push(l);
                            }
                        }
                        if(f.first+1<n){
                            if(grid[f.first+1][f.second]=='1'){
                                grid[f.first+1][f.second]='2';
                                pair<int,int> l;
                                l.first=f.first+1;
                                l.second=f.second;
                                q.push(l);
                            }
                        }
                    }
                }
            }
        }
        return num;
    }
};