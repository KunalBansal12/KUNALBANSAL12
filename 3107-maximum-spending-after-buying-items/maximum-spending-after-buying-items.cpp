class p{
    public:
    long long cost;
    int i;
    int j;
    p(long long a,int b,int c){
        cost=a;
        i=b;
        j=c;
    }
    p(){}
};

class compa{
    public:
    bool operator()(p&a,p&b){
        if(a.cost>b.cost) return true;
        else return false;
    }
};

class Solution {
public:
    long long maxSpending(vector<vector<int>>& values) {
        int n=values.size(),m=values[0].size();
        priority_queue<p,vector<p>,compa> pq;
        for(int i=0;i<n;i++){
            pq.push(p(values[i][m-1],i,m-1));
        }
        long long ans=0;
        long long l=1;
        while(pq.size()){
            p t=pq.top();
            pq.pop();
            ans+=(t.cost*l);
            if(t.j!=0){
                pq.push(p(values[t.i][t.j-1],t.i,t.j-1));
            }
            l++;
        }
        return ans;
    }
};