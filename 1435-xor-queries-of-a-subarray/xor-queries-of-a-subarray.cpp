class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int k=arr[0];
        for(int i=1;i<arr.size();i++){
            k=k^arr[i];
            arr[i]=k;
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int j=arr[queries[i][1]];
            j=arr[queries[i][1]]^(queries[i][0]==0 ? 0 : arr[queries[i][0]-1]);
            ans.push_back(j);
        }
        return ans;
    }
};