class Solution {
public:
class DisjointSet {
    unordered_map<int,int> rank, parent;
public:
    DisjointSet(int i,vector<vector<int>>& meetings,int duration) {
        // rank.resize(n + 1, 0);
        // parent.resize(n + 1);
        for (int j = i; j < meetings.size(); j++) {
            if(meetings[j][2]==duration){
                parent[meetings[j][0]]=meetings[j][0];
                parent[meetings[j][1]]=meetings[j][1];
            }
            else break;
        }
    }

    // ~DisjointSet(){
    //     rank.resize(0);
    //     parent.resize(0);
    // }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            if(ulp_v<ulp_u){
                parent[ulp_u]=ulp_v;
                rank[ulp_v]++;
            }
            else if(ulp_v>ulp_u){
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
    }
};


    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        auto compare= [](const vector<int>& a, const vector<int>& b){
            if(a[2]==b[2]){
                return a[0] < b[0];
            }
            else{
                return a[2] < b[2];
            }
        };

        sort(meetings.begin(),meetings.end(), compare);
        for(auto it: meetings){
            for(auto ij: it){
                cout<<ij<<" ";
            }
            cout<<endl;
        }
        int i=0;
        int size=meetings.size();
        unordered_map<int,int> map;
        map[0]=1;
        map[firstPerson]=1;

        while(i<size){
            int j=i;
            int currentTime=meetings[j][2];
            bool flag=false;
            // int size1=0;
            // for(int x=i; x<size && meetings[x][2]==currentTime;){
            //     size1+=2;
            //     x++;
            // }
            DisjointSet ds(i,meetings,currentTime);
            while(j<size && meetings[j][2] == currentTime){
                ds.unionByRank(meetings[j][0],meetings[j][1]);
                if(map[meetings[j][0]]==1 || map[meetings[j][1]]==1){
                    map[ds.findUPar(meetings[j][0])]=1;
                    map[ds.findUPar(meetings[j][1])]=1;
                    map[meetings[j][0]]==1;
                    map[meetings[j][1]]==1;
                }
                j++;
            }
            int k=i;

            while(k<size && meetings[k][2] == currentTime){
                if(map[ds.findUPar(meetings[k][1])] == 1){
                    map[meetings[k][1]]=1;
                }
                if(map[ds.findUPar(meetings[k][0])] == 1){
                    map[meetings[k][0]]=1;
                }
                k++;
            }
            // ds.~DisjointSet();
            i=j;
        }
        vector<int> ans;
        for(auto it: map){
            if(it.second==1) ans.push_back(it.first);
        }
        return ans;
    }
};