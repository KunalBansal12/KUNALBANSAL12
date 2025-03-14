class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long int sum=0;
        int mini=10000000,maxi=0;
        for(int i=0;i<candies.size();i++){
            sum+=candies[i];
            if(mini>candies[i]) mini=candies[i];
            if(maxi<candies[i]) maxi=candies[i];
        }
        if(k>sum) return 0;
        else if(k==sum) return 1;
        int l=1,r=maxi;
        int mid=0,ans=0;
        while(l<=r){
            mid=l+(r-l)/2;
            long int num=0;
            for(int i=0;i<candies.size();i++){
                num+=(candies[i]/mid);
            }
            if(k>num) r=mid-1;
            else{
                l=mid+1;
                ans=max(mid,ans);
            }
        }
        return ans;
    }
};