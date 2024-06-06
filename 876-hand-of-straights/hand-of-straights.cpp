class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> map;
        sort(hand.begin(),hand.end());
        for(int i=0;i<hand.size();i++){
            map[hand[i]]++;
        }
        for(int i=0;i<hand.size();i++){
            if(map[hand[i]]){
                int k=map[hand[i]];
                int n=hand[i];
                for(int i=0;i<groupSize;i++){
                    if(map[n+i]<k) return false;
                    map[n+i]-=k;
                }
            }
        }
        return true;
    }
};