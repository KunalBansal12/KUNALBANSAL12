class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size();
        int i=n-1,j=0;
        while(i>=0 && j<m){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target){
                if(j==m-1) return false;
                else j++;
            }
            else{
                if(i==0) return false;
                else i--;
            }
        }
        return false;
    }
};