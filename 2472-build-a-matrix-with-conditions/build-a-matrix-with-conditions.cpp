class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& row, vector<vector<int>>& col) {
        vector<vector<int>> graph1(k+1),graph2(k+1);
        vector<int> in1(k+1,0),in2(k+1,0);
        for(int i=0;i<row.size();i++){
            graph1[row[i][0]].push_back(row[i][1]);
            in1[row[i][1]]++;
        }
        for(int i=0;i<col.size();i++){
            graph2[col[i][0]].push_back(col[i][1]);
            in2[col[i][1]]++;
        }
        vector<int> vis1(k+1,-1),vis2(k+1,-1);
        int n1=0,n2=0;
        queue<int> q;
        for(int i=1;i<=k;i++){
            if(in1[i]==0) q.push(i);
        }
        while(q.size()){
            int node=q.front();
            cout<<node<<endl;
            q.pop();
            vis1[node]=n1++;
            for(int i=0;i<graph1[node].size();i++){
                in1[graph1[node][i]]--;
                if(in1[graph1[node][i]]==0) q.push(graph1[node][i]);
            }
        }
        if(n1!=k){
            vector<vector<int>> ans;
            return ans;
        }
        for(int i=1;i<=k;i++){
            if(in2[i]==0) q.push(i);
        }
        while(q.size()){
            int node=q.front();
            q.pop();
            vis2[node]=n2++;
            for(int i=0;i<graph2[node].size();i++){
                in2[graph2[node][i]]--;
                if(in2[graph2[node][i]]==0) q.push(graph2[node][i]);
            }
        }
        if(n2!=k){
            vector<vector<int>> ans;
            return ans;
        }
        vector<vector<int>> ans(k,vector<int>(k,0));
        for(int i=1;i<=k;i++){
            ans[vis1[i]][vis2[i]]=i;
        }
        return ans;
    }
};