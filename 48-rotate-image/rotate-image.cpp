class Solution {
public:
    vector<vector<int>> helper(vector<vector<int>>& matrix,int si,int ei){
        if(si>=ei){
            return matrix;
        }
        matrix=helper(matrix,si+1,ei-1);
        for(int i=0;i<ei-si;i++){
            swap(matrix[si][si+i],matrix[si+i][ei]);
            swap(matrix[si][si+i],matrix[ei][ei-i]);
            swap(matrix[si][si+i],matrix[ei-i][si]);
        }
        return matrix;
    }

    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        matrix=helper(matrix,0,n-1);
    }
};