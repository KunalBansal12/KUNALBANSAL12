class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int ans=INT_MAX;
        for(int i=0;i<timePoints.size()-1;i++){
            int k=stoi(timePoints[i].substr(0,2));
            int l=stoi(timePoints[i].substr(3,2));
            int num=k*60+l;
            k=stoi(timePoints[i+1].substr(0,2));
            l=stoi(timePoints[i+1].substr(3,2));
            int num1=k*60+l;
            ans=min(ans,min(num1-num,1440-num1+num));
        }
        int k=stoi(timePoints[0].substr(0,2));
        int l=stoi(timePoints[0].substr(3,2));
        int num=k*60+l;
        k=stoi(timePoints[timePoints.size()-1].substr(0,2));
        l=stoi(timePoints[timePoints.size()-1].substr(3,2));
        int num1=k*60+l;
        ans=min(ans,min(num1-num,1440-num1+num));
        return ans;
    }
};