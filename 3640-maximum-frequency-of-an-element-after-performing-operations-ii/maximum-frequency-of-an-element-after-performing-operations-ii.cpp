class Solution {
public:
    #define ll long long
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int finalans=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int j=0,l=0;
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++) map[nums[i]]++;
        while(j<n){
            while(l<n && nums[l]<=(ll)(nums[j])+2*k) l++;
            finalans=max(finalans,min(l-j,numOperations));
            j++;
        }
        j=0,l=0;
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]) continue;
            while(j<n && (ll)(nums[j])+k<nums[i]) j++;
            while(l<n && (ll)(nums[l])-k<=nums[i]) l++;
            finalans=max(finalans,map[nums[i]]+max(0,min(l-j-map[nums[i]],numOperations)));
        }
        return finalans;
    }
};