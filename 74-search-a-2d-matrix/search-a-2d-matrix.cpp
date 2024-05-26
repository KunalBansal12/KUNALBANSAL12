class Solution {
public:
    bool helper(vector<vector<int>>& matrix,int target,int si, int ei,int i){
        while(si<=ei){
            int mid=(si+(ei-si)/2);
            if(matrix[i][mid]==target) return true;
            else if(matrix[i][mid]<target) si=mid+1;
            else if(matrix[i][mid]>target) ei=mid-1;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int si=0,ei=n-1;
        bool ans=false;
        while(si<=ei){
            int mid=si+(ei-si)/2;
            if(matrix[mid][m-1]<target){
                si=mid+1;
            }
            else if(matrix[mid][0]>target){
                ei=mid-1;
            }
            else{
                ans=helper(matrix,target,0,m-1,mid);
                break;
            }
        }
        return ans;
    }
};