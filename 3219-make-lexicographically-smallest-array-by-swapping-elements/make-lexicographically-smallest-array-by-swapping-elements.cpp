class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> pairs;
        for(int i=0;i<nums.size();i++){
            pairs.push_back({nums[i],i});
        }
        sort(pairs.begin(),pairs.end());

        vector<vector<int>> group;
        group.push_back({pairs[0].second});
        for(int i=1;i<pairs.size();i++){
            if(pairs[i].first-pairs[i-1].first<=limit) group.back().push_back(pairs[i].second);
            else group.push_back({pairs[i].second});
        }
        int num=0;
        for(auto it:group){
            sort(it.begin(),it.end());
            for(int i=0;i<it.size();i++){
                nums[it[i]]=pairs[num].first;
                num++;
            }
        }
        return nums;
    }
};