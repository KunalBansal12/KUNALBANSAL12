class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(intervals.begin(),intervals.end());
        int ans=0;
        for(int i=0;i<intervals.size();i++){
            if(!pq.size()){
                pq.push(intervals[i][1]);
                ans++;
            }
            else{
                if(pq.top()<intervals[i][0]){
                    pq.pop();
                    pq.push(intervals[i][1]);
                }
                else{
                    pq.push(intervals[i][1]);
                    ans++;
                }
            }
        }
        return ans;
    }
};