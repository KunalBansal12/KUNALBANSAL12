class p{
    public:
    int start,end;
    p(int a,int b){
        start=a;
        end=b;
    }
    p(){}
};

class compa{
    public:
    bool operator()(p&a,p&b){
        if(a.start>b.start) return true;
        else if(a.start==b.start && a.end>b.end) return true;
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
        int i=0;
        while(pq.size()){
            vector<int> num;
            num.push_back(pq.top().start);
            int e=pq.top().end;
            pq.pop();
            while(pq.size() && pq.top().start<=e){
                if(e<pq.top().end) e=pq.top().end;
                pq.pop();
            }
            num.push_back(e);
            ans.push_back(num);
        }
        return ans;
    }
};