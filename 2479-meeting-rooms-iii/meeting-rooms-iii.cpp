#define ll long long int
class p{
    public:
    int roomnum;
    ll duration;
    p(int a,ll b){
        roomnum=a;
        duration=b;
    }
};
class compa{
    public:
    bool operator()(p&a,p&b){
        if(a.duration<b.duration) return false;
        else if(a.duration>b.duration) return true;
        else{
            if(a.roomnum<b.roomnum) return false;
            else return true;
        }
    }
};
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m=meetings.size();
        priority_queue<p,vector<p>,compa> pq;
        priority_queue<int,vector<int>,greater<int>> rn;
        unordered_map<int,int> map;
        sort(meetings.begin(),meetings.end());
        int i=1;
        while(i<n){
            rn.push(i);
            i++;
        }
        pq.push(p(0,meetings[0][1]));
        map[0]++;
        i=1;
        while(i<m){
            ll dur=meetings[i][0];
            ll val=-1;
            if(dur>=pq.top().duration){
                while(pq.size() && pq.top().duration<=dur){
                    rn.push(pq.top().roomnum);
                    pq.pop();
                }
            }
            else if(pq.size()==n){
                val=pq.top().duration-meetings[i][0];
                rn.push(pq.top().roomnum);
                pq.pop();
            }
            int room=rn.top();
            rn.pop();
            map[room]++;
            if(val==-1) pq.push(p(room,meetings[i][1]));
            else pq.push(p(room,meetings[i][1]+val));
            i++;
        }
        int ans=0,maxi=0;
        for(auto it:map){
            if(it.second>maxi){
                maxi=it.second;
                ans=it.first;
            }
            else if(it.second==maxi && it.first<ans){
                ans=it.first;
            }
        }
        return ans;
    }
};