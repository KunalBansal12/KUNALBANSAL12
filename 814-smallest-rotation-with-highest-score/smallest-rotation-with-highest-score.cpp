class Solution {
public:
#define pi pair<int,int>

    int bestRotation(vector<int>& nums) {
        int n=nums.size();
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(int i=0;i<n;i++){
            int start=0,end=0;
            if(nums[i]>i){
                start=i+1;
                end=min(n-1,n-nums[i]+i);
            }
            else if(nums[i]<=i){
                int start1=0,end1=0;
                end1=i-nums[i];
                pq.push({start1,end1});
                // cout<<i<<" "<<start1<<" "<<end1<<endl;
                if(end1==n-1) continue;
                start=i+1;
                end=n-1;
            }
            // cout<<i<<" "<<start<<" "<<end<<endl;
            pq.push({start,end});
        }
        int ans=0,maxi=0,num=0;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            if(!pq.size()) break;
            // int count=0;
            while(pq.size() && pq.top().first==i){
                map[pq.top().second]++;
                num++;
                // if(pq.top().second==i) count++;
                pq.pop();
            }
            if(maxi<num){
                num=maxi;
                ans=i;
            }
            num-=map[i];
        }
        return ans;
    }
};