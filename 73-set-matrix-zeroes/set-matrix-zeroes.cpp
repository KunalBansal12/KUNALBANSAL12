class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()==1 && matrix[0].size()==1) return;
        int left=0,right=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    if(j==0) left=1;
                    if(i==0) right=1;
                }
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=matrix.size()-1;i>0;i--){
            for(int j=matrix[0].size()-1;j>0;j--){
                if(matrix[0][j]==0 || matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(left==1){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0]=0;
            }
        }
        if(right==1){
            for(int i=0;i<matrix[0].size();i++){
                matrix[0][i]=0;
            }
        }
        return;
    }
};