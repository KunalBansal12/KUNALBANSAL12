class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        int i=0,j=1,maxi=1;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q1;
        priority_queue<pair<int,int>> q2;
        q1.push({nums[0],0});
        q2.push({nums[0],0});
        while(j<n){
            while(q1.size()&&q1.top().second<i){
                q1.pop();
            }
            while(q2.size()&&q2.top().second<i){
                q2.pop();
            }
            if(q1.empty()||q2.empty()){
                q1.push({nums[j],j});
                q2.push({nums[j],j});
                i=j;
                j++;
            }
            else{
                q1.push({nums[j],j});
                q2.push({nums[j],j});
                int mini=q1.top().first;
                int maxi=q2.top().first;
                if(abs(mini-maxi)>limit){
                    i=min(q1.top().second+1,q2.top().second+1);
                }
                else{
                    j++;
                }
            }
            maxi=max(maxi,j-i);
        }
        return maxi;
    }
};