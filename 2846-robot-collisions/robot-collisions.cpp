class p{
    private:
    public:
    int pos,heal;
    char direc;
    p(int a,int b,char c){
        pos=a;
        heal=b;
        direc=c;
    }
    p(){};
};
class compa{
    public:
    bool operator()(p&a,p&b){
        if(a.pos>b.pos) return true;
        return false;
    }
};
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        priority_queue<p,vector<p>,compa> pq;
        for(int i=0;i<positions.size();i++){
            pq.push(p(positions[i],healths[i],directions[i]));
        }
        stack<p> s;
        unordered_map<int,int> map;
        while(pq.size()){
            p pt=pq.top();
            pq.pop();
            if(pt.direc=='L'){
                if(s.empty()) map[pt.pos]=pt.heal;
                else{
                    while(!s.empty()){
                        if(pt.heal>s.top().heal){
                            map[s.top().pos]=0;
                            s.pop();
                            pt.heal-=1;
                        }
                        else if(pt.heal==s.top().heal){
                            map[s.top().pos]=0;
                            map[pt.pos]=0;
                            s.pop();
                            break;
                        }
                        else{
                            map[pt.pos]=0;
                            s.top().heal-=1;
                            break;
                        }
                    }
                    if(map.find(pt.pos)==map.end()) map[pt.pos]=pt.heal;
                }
            }
            else{
                s.push(pt);
            }
        }
        while(!s.empty()){
            map[s.top().pos]=s.top().heal;
            s.pop();
        }
        vector<int> ans;
        for(int i=0;i<positions.size();i++){
            if(map[positions[i]]!=0) ans.push_back(map[positions[i]]);
        }
        return ans;
    }
};