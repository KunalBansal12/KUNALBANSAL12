class Solution {
public:
    int dfs(int n,int id,vector<int>& t,unordered_map<int,vector<int>>& map){
        int ans=t[id];
        int j=0;
        for(int i=0;i<map[id].size();i++){
            j=max(j,dfs(n,map[id][i],t,map));
        }
        return ans+j;
    }

    int numOfMinutes(int n, int headID, vector<int>& m, vector<int>& t) {
        unordered_map<int,vector<int>> map;
        for(int i=0;i<n;i++){
            if(m[i]!=-1) map[m[i]].push_back(i);
        }
        return dfs(n,headID,t,map);
    }
};