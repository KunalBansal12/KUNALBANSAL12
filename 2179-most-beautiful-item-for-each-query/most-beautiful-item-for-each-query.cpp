class compa{
    public:
    bool operator()(pair<int,int>&a,pair<int,int>&b){
        if(a.first<b.first) return true;
        else if(a.first==b.first){
            if(a.second>b.second) return true;
        }
        return false;
    }
};

class Solution {
public:
    int bs(vector<pair<int,int>>& nums,int target){
        int low=0,high=nums.size()-1,ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid].first<=target){
                ans=max(ans,nums[mid].second);
                low=mid+1;
            }
            else high=mid-1;
        }
        return ans;
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<pair<int,int>> nums;
        int maxi=0;
        for(int i=0;i<items.size();i++){
            nums.push_back({items[i][0],items[i][1]});
        }
        sort(nums.begin(),nums.end(),compa());
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i].second);
            nums[i].second=maxi;
            // cout<<maxi<<endl;
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            ans.push_back(bs(nums,queries[i]));
        }
        return ans;
    }
};