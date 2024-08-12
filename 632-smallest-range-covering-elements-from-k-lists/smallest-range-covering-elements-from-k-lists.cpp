class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int n=nums.size(),maxi=-1000000;
        for(int i=0;i<n;i++){
            pq.push({nums[i][0],{i,0}});
            maxi=max(maxi,nums[i][0]);
        }
        vector<int> ans(2,0);
        ans[0]=pq.top().first;
        ans[1]=maxi;
        while(1){
            int a=pq.top().first;
            int b=pq.top().second.first;
            int c=pq.top().second.second;
            if(c+1>=nums[b].size()) return ans;
            pq.pop();
            pq.push({nums[b][c+1],{b,c+1}});
            maxi=max(maxi,nums[b][c+1]);
            b=pq.top().first;
            if(maxi-b+1<ans[1]-ans[0]+1){
                ans[1]=maxi;
                ans[0]=b;
            }
        }
        return ans;
    }
};