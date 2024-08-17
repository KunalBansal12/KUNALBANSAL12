class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n=points.size(),m=points[0].size();
        vector<vector<long long>> dp(2, vector<long long>(m, 0));
        for (int j=0; j<m; j++){
            dp[0][j]=points[0][j];
        }
        for (int i=1; i < n; i++) {
            vector<long long> left(m,0), right(m,0);

             // Compute max from right downto col j=c-1...0
            right[m-1]=dp[(i-1)&1][m-1];
            for (int j=m-2; j >= 0; j--)
                right[j] = max(right[j+1]-1, dp[(i-1)&1][j]);

            // Compute max from left to col j=0...c-1
            left[0]=dp[(i-1)&1][0];
            dp[i&1][0]=max(left[0], right[0])+points[i][0];
            for (int j=1; j < m; j++){
                left[j]=max(left[j-1]-1, dp[(i-1)&1][j]);
                dp[i&1][j] = max(left[j], right[j])+points[i][j];// update DP
            }
        }

        // Find the maximum value
        return *max_element(dp[(n-1)&1].begin(), dp[(n-1)&1].end());
    }
};