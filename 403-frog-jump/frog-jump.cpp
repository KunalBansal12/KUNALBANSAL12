class Solution {
public:
    int help(vector<vector<int>>& dp,vector<int>& stones,unordered_map<int,int>& map,int stone,int step){
        if(stone==stones.size()-1) return true;
        if(step==0) return false;
        if(dp[stone][step]!=-1) return dp[stone][step];
        bool temp=false;
        if(map[stones[stone]+step]) temp=temp | help(dp,stones,map,map[stones[stone]+step],step);
        if(map[stones[stone]+step+1]) temp=temp | help(dp,stones,map,map[stones[stone]+step+1],step+1);
        if(map[stones[stone]+step-1]) temp=temp | help(dp,stones,map,map[stones[stone]+step-1],step-1);
        return dp[stone][step]=temp;
    }

    bool canCross(vector<int>& stones) {
        int n=stones.size();
        if(stones[1]!=1) return false;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        unordered_map<int,int> map;
        for(int i=1;i<stones.size();i++) map[stones[i]]=i;
        return help(dp,stones,map,1,1);
    }
};