class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int num=INT_MAX,count=0,zerocount=0;
        long long ans=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0) zerocount++;
                if(matrix[i][j]<0){
                    count++;
                }
                num=min(num,abs(matrix[i][j]));
                ans+=abs(matrix[i][j]);
            }
        }
        if(zerocount) return ans;
        else if(count%2==0) return ans;
        return ans-2*num;
    }
};