class p{
    public:
    int leavetime;
    int chairnumber;

    p(){}
    p(int a,int b){
        leavetime=a;
        chairnumber=b;
    }
};

class compa{
    public:
    bool operator()(p& a,p& b){
        if(a.leavetime>b.leavetime) return true;
        else if(a.leavetime==b.leavetime){
            if(a.chairnumber>b.chairnumber) return true;
        }
        return false;
    }
};

class c{
    public:
    int start;
    int leave;
    int friendnum;
    c(){}
    c(int a,int b,int c){
        start=a;
        leave=b;
        friendnum=c;
    }
};

class compari{
    public:
    bool operator()(c& a,c& b){
        if(a.start>b.start) return true;
        else if(a.start==b.start){
            if(a.leave>b.leave) return true;
            else if(a.leave==b.leave && a.friendnum>b.friendnum) return true;
        }
        return false;
    }
};

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<p,vector<p>,compa> pq;
        priority_queue<c,vector<c>,compari> pq1;
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<times.size();i++){
            pq1.push(c(times[i][0],times[i][1],i));
        }
        int num=1;
        q.push(0);
        while(pq1.size()){
            int s=pq1.top().start;
            int l=pq1.top().leave;
            int n=pq1.top().friendnum;
            pq1.pop();
            while(pq.size() && pq.top().leavetime<=s){
                q.push(pq.top().chairnumber);
                pq.pop();
            }
            if(!q.size()){
                q.push(num);
                num++;
            }
            int ans=0;
            int seat=q.top();
            q.pop();
            pq.push(p(l,seat));
            ans=seat;
            if(n==targetFriend) return ans;
        }
        return 0;
    }
};