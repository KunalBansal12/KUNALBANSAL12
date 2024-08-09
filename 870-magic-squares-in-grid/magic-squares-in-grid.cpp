class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        if(n<3 || m<3) return 0;
        int ans=0;
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m-2;j++){
                bool check=true;
                unordered_map<int,int> map;
                for(int k=0;k<3;k++){
                    int sum=0;
                    for(int l=0;l<3;l++){
                        sum+=grid[i+k][j+l];
                        if(grid[i+k][j+l]>9) check=false;
                        if(map[grid[i+k][j+l]]==1) check=false;
                        map[grid[i+k][j+l]]++;
                    }
                    if(sum!=15){
                        check=false;
                        break;
                    }
                }
                if(!check) continue;
                for(int k=0;k<3;k++){
                    int sum=0;
                    for(int l=0;l<3;l++){
                        sum+=grid[i+l][j+k];
                    }
                    if(sum!=15){
                        check=false;
                        break;
                    }
                }
                if(!check) continue;
                int sum1=0,sum2=0,l=j;
                for(int k=0;k<3;k++){
                    sum1+=grid[i+k][l+k];
                    sum2+=grid[i+k][l+2-k];
                }
                if(sum1!=sum2) continue;
                ans++;
            }
        }
        return ans;
    }
};