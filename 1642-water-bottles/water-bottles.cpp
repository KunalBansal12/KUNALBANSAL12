class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        while(numBottles>=numExchange){
            int n=numBottles/numExchange;
            ans+=n;
            numBottles=n+numBottles%numExchange;
        }
        return ans;
    }
};