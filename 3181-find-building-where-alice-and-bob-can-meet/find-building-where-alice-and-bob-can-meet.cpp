class Solution {
public:
    void build(int ind,int low,int high, vector<int>& heights, vector<int>& seg){
        if(low==high){
            seg[ind]=heights[low];
            return;
        }
        int mid=(high+low)/2;
        build(2*ind+1,low,mid,heights,seg);
        build(2*ind+2,mid+1,high,heights,seg);
        seg[ind]=max(seg[2*ind+1],seg[2*ind+2]);
        return;
    }

    int query(int ind,int low,int high,int l,int r,int h1,int h2, vector<int>& heights, vector<int>& seg){
        if(low==high){
            if(seg[ind]>h1) return low;
            return -1;
        }
        if(r<low || l>high) return -1;
        if(low>=l && high<=r){
            if(seg[ind]>h1){
                int mid=(low+high)/2;
                int left=query(2*ind+1,low,mid,l,r,h1,h2,heights,seg);
                if(left!=-1) return left;
                int right=query(2*ind+2,mid+1,high,l,r,h1,h2,heights,seg);
                return right;
            }
            return -1;
        }
        int mid=(low+high)/2;
        int left=query(2*ind+1,low,mid,l,r,h1,h2,heights,seg);
        if(left!=-1) return left;
        int right=query(2*ind+2,mid+1,high,l,r,h1,h2,heights,seg);
        if(right!=-1) return right;
        return -1;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();
        vector<int> seg(4*n+1,0);
        build(0,0,n-1,heights,seg);
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==queries[i][1]){
                ans.push_back(queries[i][0]);
                continue;
            }
            if(queries[i][0]>queries[i][1]){
                swap(queries[i][0],queries[i][1]);
            }
            if(heights[queries[i][1]]>heights[queries[i][0]]){
                ans.push_back(queries[i][1]);
                continue;
            }
            if(queries[i][1]==n-1){
                ans.push_back(-1);
                continue;
            }
            int a=query(0,0,n-1,queries[i][1]+1,n-1,heights[queries[i][0]],heights[queries[i][1]],heights,seg);
            ans.push_back(a);
        }
        return ans;
    }
};