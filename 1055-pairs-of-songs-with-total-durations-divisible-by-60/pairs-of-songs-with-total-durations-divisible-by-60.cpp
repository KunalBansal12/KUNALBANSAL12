class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> map;
        for(int i=0;i<time.size();i++){
            map[time[i]%60]++;
        }
        long long ans=0;
        for(int i=0;i<time.size();i++){
            int j=60-time[i]%60;
            ans+=map[j];
            if(j==60) ans+=map[0]-1;
            else if(j==30) ans--;
        }
        return ans/2;
    }
};