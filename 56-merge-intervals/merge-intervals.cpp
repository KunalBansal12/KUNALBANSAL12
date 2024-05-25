class p{
    public:
    int start,end;
    p(){};
    p(int x,int y){
        start=x,end=y;
    }
};

class compa{
    public:
    bool operator()(p&a,p&b){
        if(a.end<b.end) return true;
        else if(a.end==b.end){
            if(a.start<b.start) return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<p,vector<p>,compa> pq;
        for(int i=0;i<intervals.size();i++){
            pq.push(p(intervals[i][0],intervals[i][1]));
        }
        vector<vector<int>> ans;
        while(pq.size()){
            vector<int> a1(2,0);
            a1[0]=pq.top().start;
            a1[1]=pq.top().end;
            while(pq.size() && pq.top().end>=a1[0]){
                a1[0]=min(a1[0],pq.top().start);
                pq.pop();
            }
            ans.push_back(a1);
        }
        return ans;
    }
};