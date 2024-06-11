class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans;
        map<int,int>mp;
        for(auto it:arr1){
            mp[it]++;
        }
        for(int i=0;i<arr2.size();i++){
            int n = mp[arr2[i]];
            for(int j=0;j<n;j++){
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
                if(mp[arr2[i]]==0) mp.erase(arr2[i]);
            }
        }
        for(auto it:mp){
            for(int i=0;i<it.second;i++){
            ans.push_back(it.first);
            }
        }
        return ans;
    }
};