class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int,vector<int>> map;
        map[0].push_back(0);
        int num=0,ans=0;
        for(int i=0;i<arr.size();i++){
            num=num^arr[i];
            if(map[num].size()){
                for(int j=0;j<map[num].size();j++){
                    ans+=i-map[num][j];
                }
            }
            map[num].push_back(i+1);
        }
        return ans;
    }
};