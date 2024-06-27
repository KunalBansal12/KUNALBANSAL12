class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> map;
        for(int i=0;i<edges.size();i++){
            if(map[edges[i][0]]>=1) return edges[i][0];
            if(map[edges[i][1]]>=1) return edges[i][1];
            map[edges[i][0]]++;
            map[edges[i][1]]++;
        }
        return edges[0][0];
    }
};