class Solution {
public:
    #define ll long long
    int minOperations(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int ans=0;
        while(pq.size()){
            ll a=pq.top();
            pq.pop();
            ll b=pq.top();
            pq.pop();
            if(a>=k && b>=k) break;
            pq.push(2*a+b);
            ans++;
        }
        return ans;
    }
};