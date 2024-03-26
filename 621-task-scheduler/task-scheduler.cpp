class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> map;
        for(int i=0;i<tasks.size();i++){
            map[tasks[i]]++;
        }
        priority_queue<int> pq;
        for(auto it:map){
            pq.push(it.second);
        }
        int blank=0,used=0;
        int temp=pq.top();
        pq.pop();
        blank=(temp-1)*n;
        used+=blank+temp;
        while(pq.size()){
            int nex=pq.top();
            pq.pop();
            if(blank<=0){
                used+=nex;
            }
            else{
                if(nex==temp){
                    used++;
                    nex--;
                }
                int rem=blank-nex;
                if(rem<=0){
                    int v=nex-blank;
                    blank=0;
                    used+=v;
                }
                else{
                    blank-=nex;
                }
            }
        }
        return used;
    }
};