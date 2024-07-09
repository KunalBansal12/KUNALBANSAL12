class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=0;
        int time=0;
        for(int i=0;i<customers.size();i++){
            if(i==0){
                ans=customers[i][1];
                time=customers[i][1]+customers[i][0];
            }
            else{
                if(time<=customers[i][0]){
                    ans+=customers[i][1];
                    time=customers[i][1]+customers[i][0];
                }
                else{
                    time+=customers[i][1];
                    ans+=time-customers[i][0];
                }
            }
        }
        return ans/((double)(customers.size()));
    }
};