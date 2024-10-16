class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        string ans="";
        char ch=' ';
        int count=0;
        while(pq.size()){
            auto t=pq.top();
            pq.pop();
            if(count==2 && t.second==ch){
                pair<int,char> j;
                if(pq.size()) j=pq.top();
                else return ans;
                pq.pop();
                ans+=j.second;
                if(j.first>1) pq.push({j.first-1,j.second});
                pq.push({t.first,t.second});
                ch=j.second;
                count=1;
            }
            else{
                ans+=t.second;
                if(ch==t.second) count++;
                else{
                    ch=t.second;
                    count=1;
                }
                if(t.first>1) pq.push({t.first-1,t.second});
            }
        }
        return ans;
    }
};