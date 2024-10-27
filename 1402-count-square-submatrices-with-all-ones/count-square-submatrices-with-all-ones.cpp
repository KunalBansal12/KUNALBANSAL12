class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> left(n,vector<int>(m,0)),right(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            int ans=0;
            for(int j=0;j<m;j++){
                if(matrix[i][j]==1) ans++;
                else ans=0;
                left[i][j]=ans;
            }
        }
        for(int i=0;i<m;i++){
            int ans=0;
            for(int j=0;j<n;j++){
                if(matrix[j][i]==1) ans++;
                else ans=0;
                right[j][i]=ans;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) continue;
                int num=2;
                ans++;
                int k=i+1,l=j+1;
                while(k<n && l<m){
                    if(left[k][l]<num || right[k][l]<num) break;
                    ans++;
                    k++;
                    l++;
                    num++;
                }
            }
        }
        return ans;
    }
};