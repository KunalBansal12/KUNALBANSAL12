class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        vector<vector<int>> matrix(n,vector<int>(n,false));
	    for(int i=0;i<pre.size();i++) matrix[pre[i][0]][pre[i][1]]=true;
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                if(matrix[i][k]==false || matrix[k][j]==false) continue;
	                matrix[i][j]=true;
	            }
	        }
	    }
	    vector<bool> ans;
        for(int i=0;i<q.size();i++){
            if(matrix[q[i][0]][q[i][1]]) ans.push_back(true);
            else ans.push_back(false);
        }
	    return ans;
    }
};