class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int ans=0;
        int i=0;
        while(i<rolls.size()){
            unordered_map<int,int> map;
            int num=0;
            while(i<rolls.size() && num!=k){
                map[rolls[i]]++;
                if(map[rolls[i]]==1) num++;
                i++;
            }
            if(num==k) ans++;
        }
        return ans+1;
    }
};